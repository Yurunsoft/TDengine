---
title: 建立连接
--- 

import Tabs from "@theme/Tabs";
import TabItem from "@theme/TabItem";
import ConnJava from "./_connect_java.mdx";
import ConnGo from "./_connect_go.mdx";
import ConnRust from "./_connect_rust.mdx";
import ConnNode from "./_connect_node.mdx";
import ConnPythonNative from "./_connect_python.mdx";
import ConnCSNative from "./_connect_cs.mdx";
import ConnC from "./_connect_c.mdx";
import ConnR from "./_connect_r.mdx";
import InstallOnWindows from "../14-reference/03-connector/_linux_install.mdx";
import InstallOnLinux from "../14-reference/03-connector/_windows_install.mdx";
import VerifyLinux from "../14-reference/03-connector/_verify_linux.mdx";
import VerifyWindows from "../14-reference/03-connector/_verify_windows.mdx";

TDengine 提供 RESTful 接口，容许在任何平台的任何应用程序通过它访问TDengine运行实例，详细介绍请看 [REST API](/reference/rest-api/)。除 REST API 之外，TDengine 还提供多种编程语言的连接器方便用户开发应用程序，其中包括 C/C++、Java、Python、Go、Node.js、C# 等。 本节介绍如何使用连接器建立与 TDengine 的连接，给出连接器安装、连接的简单说明。关于各连接器的详细功能说明，请查看[连接器](https://docs.taosdata.com/reference/connector/)

## 连接器建立连接的方式

连接器建立连接的方式，TDengine提供两种:
  1. 通过 taosAdapter 组件提供的 REST API 建立与 taosd 的连接，这种连接方式下文中简称"RESTful 连接“ 
  2. 通过客户端驱动程序 taosc 直接与服务端程序 taosd 建立连接，这种连接方式下文中简称“本地连接”。

无论使用何种方式建立连接，连接器都提供了相同或相似的 API 操作数据库，都可以执行 SQL 语句，只是初始化连接的方式稍有不同，用户在使用上不会感到什么差别。

关键不同点在于：
1. 使用 RESTful 连接，用户无需安装客户端驱动程序 taosc，具有跨平台易用的优势，但性能要下降30%左右。
2. 使用本地连接可以体验 TDengine 的全部功能，如[原生接口写入](/reference/connector/cpp#参数绑定-api)、[订阅](reference/connector/cpp#数据订阅接口)等等。


## 安装客户端驱动 taosc

如果选择本地连接，而且应用程序不在 TDengine 同一台服务器上运行，你需要先安装客户端驱动，否则可以跳过此一步。为避免客户端驱动和服务端不兼容，请使用一致的版本。

### 安装步骤

<Tabs defaultValue="linux" groupId="os">
  <TabItem value="linux" label="Linux">
    <InstallOnWindows />
  </TabItem>
  <TabItem value="windows" label="Windows">
    <InstallOnLinux />
  </TabItem>
</Tabs>

### 安装验证

以上安装和配置完成后，并确认 TDengine 服务已经正常启动运行，此时可以执行安装包里带有的 TDengine 命令行程序 taos 进行登录。

<Tabs defaultValue="linux" groupId="os">
  <TabItem value="linux" label="Linux">
    <VerifyLinux />
  </TabItem>
  <TabItem value="windows" label="Windows">
    <VerifyWindows />
  </TabItem>
</Tabs>

## 安装连接器

<Tabs groupId="lang">
<TabItem label="Java" value="java">
  
如果使用 maven 管理项目，只需在 pom.xml 中加入以下依赖。

```xml
<dependency>
  <groupId>com.taosdata.jdbc</groupId>
  <artifactId>taos-jdbcdriver</artifactId>
  <version>2.0.38</version>
</dependency>
```

</TabItem>
<TabItem label="Python" value="python">

使用 `pip` 从 PyPI 安装:
```
pip install taospy
```
从 Git URL 安装：
```
pip install git+https://github.com/taosdata/taos-connector-python.git
```

</TabItem>
<TabItem label="Go" value="go">

编辑 `go.mod` 添加 `driver-go` 依赖即可。
```go-mod title=go.mod
module goexample

go 1.17

require github.com/taosdata/driver-go/v2 develop
```
:::note
driver-go 使用 cgo 封装了 taosc 的 API。cgo 需要使用 gcc 编译 C 的源码。因此需要确保你的系统上有 gcc。

:::

</TabItem>
<TabItem label="Rust" value="rust">

编辑 `Cargo.toml` 添加 `libtaos` 依赖即可。
```toml title=Cargo.toml
[dependencies]
libtaos = { version = "0.4.2"}
```
:::info
Rust 连接器通过不同的特性区分不同的连接方式。如果要建立 RESTful 连接，需要开启 `rest` 特性：
```toml
libtaos = { version = "*", features = ["rest"] }
```

:::

</TabItem>
<TabItem label="Node.js" value="node">

Node.js 连接器通过不同的包提供不同的连接方式。

1. 安装 Node.js 本地连接器
  ```
  npm i td2.0-connector
  ```
  :::note
  推荐Node版本大于等于 `node-v12.8.0` 小于 `node-v13.0.0` 

  :::
2. 安装 Node.js RESTful 连接器
  ```
  npm i td2.0-rest-connector
  ```

</TabItem>
<TabItem label="C#" value="csharp">

编辑项目配置文件中添加 [TDengine.Connector](https://www.nuget.org/packages/TDengine.Connector/) 的引用即可：

```xml title=csharp.csproj {12}
<Project Sdk="Microsoft.NET.Sdk">

  <PropertyGroup>
    <OutputType>Exe</OutputType>
    <TargetFramework>net6.0</TargetFramework>
    <ImplicitUsings>enable</ImplicitUsings>
    <Nullable>enable</Nullable>
    <StartupObject>TDengineExample.AsyncQueryExample</StartupObject>
  </PropertyGroup>

  <ItemGroup>
    <PackageReference Include="TDengine.Connector" Version="1.0.6" />
  </ItemGroup>

</Project>
```
也可通过 dotnet 命令添加：
```
dotnet add package TDengine.Connector
```
:::note 
以下示例代码，均基于 dotnet6.0，如果使用其它版本，可能需要做适当调整。 

:::

</TabItem>
<TabItem label="R" value="r">

1. 下载 [taos-jdbcdriver-version-dist.jar](https://repo1.maven.org/maven2/com/taosdata/jdbc/taos-jdbcdriver/2.0.38/)。
2. 安装 R 的依赖包`RJDBC`：
```R
install.packages("RJDBC")
```
</TabItem>
<TabItem label="C" value="c">

如果已经安装了 TDengine 服务端软件或 TDengine 客户端驱动 taosc， 那么已经安装了 C 连接器，无需额外操作。
<br/>

</TabItem>
</Tabs>


## 建立连接

在执行这一步之前，请确保有一个正在运行的，且可以访问到的 TDengine，而且服务端的FQDN配置正确。以下示例代码，都假设 TDengine 安装在本机，且 FQDN（默认 localhost） 和 serverPort（默认 6030） 都使用默认配置。

<Tabs groupId="lang" defaultValue="java">
  <TabItem label="Java" value="java">
    <ConnJava />
  </TabItem>
  <TabItem label="Python" value="python">
    <ConnPythonNative />
  </TabItem>
  <TabItem label="Go" value="go">
      <ConnGo />
  </TabItem>
  <TabItem label="Rust" value="rust">
    <ConnRust />
  </TabItem>
  <TabItem label="Node.js" value="node">
    <ConnNode />
  </TabItem>
  <TabItem label="C#" value="csharp">
    <ConnCSNative />
  </TabItem>
  <TabItem label="R" value="r">
    <ConnR/>
  </TabItem>
  <TabItem label="C" value="c">
    <ConnC />
  </TabItem>
</Tabs>

:::tip
如果建立连接失败，大部分情况下是FQDN或防火墙的配置不正确，详细的排查方法请看[《常见问题及反馈》](https://docs.taosdata.com/train-fqa/faq)中的“遇到错误Unable to establish connection, 我怎么办？”

:::

