---
sidebar_label: 函数
title: 函数
toc_max_heading_level: 4
---

## 单行函数

单行函数为查询结果中的每一行返回一个结果行。

### 数学函数

#### ABS

```sql
  SELECT ABS(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的绝对值

**返回结果类型**：如果输入值为整数，输出值是 UBIGINT 类型。如果输入值是 FLOAT/DOUBLE 数据类型，输出值是 DOUBLE 数据类型。

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。

#### ACOS

```sql
  SELECT ACOS(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的反余弦结果

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。

#### ASIN

```sql
  SELECT ASIN(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的反正弦结果

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。


#### ATAN

```sql
  SELECT ATAN(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的反正切结果

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。


#### CEIL

```
SELECT CEIL(field_name) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：获得指定列的向上取整数的结果。

**返回结果类型**：与指定列的原始数据类型一致。例如，如果指定列的原始数据类型为 Float，那么返回的数据类型也为 Float；如果指定列的原始数据类型为 Double，那么返回的数据类型也为 Double。

**适用数据类型**：数值类型。

**适用于**: 普通表、超级表。

**嵌套子查询支持**：适用于内层查询和外层查询。

**使用说明**:

- 支持 +、-、\*、/ 运算，如 ceil(col1) + ceil(col2)。
- 只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。

#### COS

```sql
  SELECT COS(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的余弦结果

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。

#### FLOOR

```
SELECT FLOOR(field_name) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：获得指定列的向下取整数的结果。  
 其他使用说明参见 CEIL 函数描述。

#### LOG

```sql
  SELECT LOG(field_name, base) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列对于底数 base 的对数

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。


#### POW

```sql
  SELECT POW(field_name, power) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的指数为 power 的幂

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。


#### ROUND

```
SELECT ROUND(field_name) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：获得指定列的四舍五入的结果。  
 其他使用说明参见 CEIL 函数描述。


#### SIN

```sql
  SELECT SIN(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的正弦结果

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。

#### SQRT

```sql
  SELECT SQRT(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的平方根

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。

#### TAN

```sql
  SELECT TAN(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：获得指定列的正切结果

**返回结果类型**：DOUBLE。如果输入值为 NULL，输出值也为 NULL

**适用数据类型**：数值类型。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

**使用说明**：只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用。

### 字符串函数

字符串函数的输入参数为字符串类型，返回结果为数值类型或字符串类型。

#### CHAR_LENGTH

```
  SELECT CHAR_LENGTH(str|column) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：以字符计数的字符串长度。

**返回结果类型**：INT。如果输入值为NULL，输出值为NULL。

**适用数据类型**：VARCHAR, NCHAR

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表

#### CONCAT

```sql
  SELECT CONCAT(str1|column1, str2|column2, ...) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：字符串连接函数。

**返回结果类型**：如果所有参数均为 VARCHAR 类型，则结果类型为 VARCHAR。如果参数包含NCHAR类型，则结果类型为NCHAR。如果输入值为NULL，输出值为NULL。

**适用数据类型**：VARCHAR, NCHAR。 该函数最小参数个数为2个，最大参数个数为8个。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表


#### CONCAT_WS

```
  SELECT CONCAT_WS(separator, str1|column1, str2|column2, ...) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：带分隔符的字符串连接函数。

**返回结果类型**：如果所有参数均为VARCHAR类型，则结果类型为VARCHAR。如果参数包含NCHAR类型，则结果类型为NCHAR。如果输入值为NULL，输出值为NULL。如果separator值不为NULL，其他输入为NULL，输出为空串。

**适用数据类型**：VARCHAR, NCHAR。 该函数最小参数个数为3个，最大参数个数为9个。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表


#### LENGTH

```
  SELECT LENGTH(str|column) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：以字节计数的字符串长度。

**返回结果类型**：INT。

**适用数据类型**：输入参数是 VARCHAR 类型或者 NCHAR 类型的字符串或者列。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表


#### LOWER

```
  SELECT LOWER(str|column) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：将字符串参数值转换为全小写字母。

**返回结果类型**：同输入类型。如果输入值为NULL，输出值为NULL。

**适用数据类型**：输入参数是 VARCHAR 类型或者 NCHAR 类型的字符串或者列。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表


#### LTRIM

```
  SELECT LTRIM(str|column) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：返回清除左边空格后的字符串。

**返回结果类型**：同输入类型。如果输入值为NULL，输出值为NULL。

**适用数据类型**：输入参数是 VARCHAR 类型或者 NCHAR 类型的字符串或者列。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表


#### RTRIM

```
  SELECT LTRIM(str|column) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：返回清除右边空格后的字符串。

**返回结果类型**：同输入类型。如果输入值为NULL，输出值为NULL。

**适用数据类型**：输入参数是 VARCHAR 类型或者 NCHAR 类型的字符串或者列。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表


#### SUBSTR

```
  SELECT SUBSTR(str,pos[,len]) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：从源字符串 str 中的指定位置 pos 开始取一个长度为 len 的子串并返回。

**返回结果类型**：同输入类型。如果输入值为NULL，输出值为NULL。

**适用数据类型**：输入参数是 VARCHAR 类型或者 NCHAR 类型的字符串或者列。输入参数pos可以为正数，也可以为负数。如果pos是正数，表示开始位置从字符串开头正数计算。如果pos为负数，表示开始位置从字符串结尾倒数计算。如果输入参数len被忽略，返回的子串包含从pos开始的整个字串。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表


#### UPPER

```
  SELECT UPPER(str|column) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：将字符串参数值转换为全大写字母。

**返回结果类型**：同输入类型。如果输入值为NULL，输出值为NULL。

**适用数据类型**：输入参数是 VARCHAR 类型或者 NCHAR 类型的字符串或者列。

**嵌套子查询支持**：适用于内层查询和外层查询。

**适用于**: 表和超级表


### 转换函数

转换函数将值从一种数据类型转换为另一种数据类型。

#### CAST

```sql
  SELECT CAST(expression AS type_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：数据类型转换函数，输入参数 expression 支持普通列、常量、标量函数及它们之间的四则运算，只适用于 select 子句中。

**返回结果类型**：CAST 中指定的类型（type_name），可以是 BIGINT、BIGINT UNSIGNED、BINARY、VARCHAR、NCHAR和TIMESTAMP。

**适用数据类型**：输入参数 expression 的类型可以是BLOB、MEDIUMBLOB和JSON外的所有类型 

**使用说明**：

- 对于不能支持的类型转换会直接报错。
- 如果输入值为NULL则输出值也为NULL。
- 对于类型支持但某些值无法正确转换的情况对应的转换后的值以转换函数输出为准。目前可能遇到的几种情况：
        1）字符串类型转换数值类型时可能出现的无效字符情况，例如"a"可能转为0，但不会报错。
        2）转换到数值类型时，数值大于type_name可表示的范围时，则会溢出，但不会报错。
        3）转换到字符串类型时，如果转换后长度超过type_name的长度，则会截断，但不会报错。

#### TO_ISO8601

```sql
SELECT TO_ISO8601(ts_val | ts_col) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：将 UNIX 时间戳转换成为 ISO8601 标准的日期时间格式，并附加客户端时区信息。

**返回结果数据类型**：VARCHAR 类型。

**适用数据类型**：UNIX 时间戳常量或是 TIMESTAMP 类型的列

**适用于**：表、超级表。

**使用说明**：

- 如果输入是 UNIX 时间戳常量，返回格式精度由时间戳的位数决定; 
- 如果输入是 TIMSTAMP 类型的列，返回格式的时间戳精度与当前 DATABASE 设置的时间精度一致。


#### TO_JSON

```sql
SELECT TO_JSON(str_literal) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**: 将字符串常量转换为 JSON 类型。

**返回结果数据类型**: JSON

**适用数据类型**: JSON 字符串，形如 '{ "literal" : literal }'。'{}'表示空值。键必须为字符串字面量，值可以为数值字面量、字符串字面量、布尔字面量或空值字面量。str_literal中不支持转义符。

**适用于**: 表和超级表

**嵌套子查询支持**：适用于内层查询和外层查询。


#### TO_UNIXTIMESTAMP

```sql
SELECT TO_UNIXTIMESTAMP(datetime_string | ts_col) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：将日期时间格式的字符串转换成为 UNIX 时间戳。

**返回结果数据类型**：长整型 INT64。

**应用字段**：字符串常量或是 VARCHAR/NCHAR 类型的列。

**适用于**：表、超级表。

**使用说明**：

- 输入的日期时间字符串须符合 ISO8601/RFC3339 标准，无法转换的字符串格式将返回 0。
- 返回的时间戳精度与当前 DATABASE 设置的时间精度一致。


### 时间和日期函数

时间和日期函数对时间戳类型进行操作。

所有返回当前时间的函数，如NOW、TODAY和TIMEZONE，在一条SQL语句中不论出现多少次都只会被计算一次。

#### NOW

```sql
SELECT NOW() FROM { tb_name | stb_name } [WHERE clause];
SELECT select_expr FROM { tb_name | stb_name } WHERE ts_col cond_operatior NOW();
INSERT INTO tb_name VALUES (NOW(), ...);
```

**功能说明**：返回客户端当前系统时间。

**返回结果数据类型**：TIMESTAMP 时间戳类型。

**应用字段**：在 WHERE 或 INSERT 语句中使用时只能作用于 TIMESTAMP 类型的字段。

**适用于**：表、超级表。

**使用说明**：

- 支持时间加减操作，如 NOW() + 1s, 支持的时间单位如下：
        b(纳秒)、u(微秒)、a(毫秒)、s(秒)、m(分)、h(小时)、d(天)、w(周)。
- 返回的时间戳精度与当前 DATABASE 设置的时间精度一致。


#### TIMEDIFF

```sql
SELECT TIMEDIFF(ts_val1 | datetime_string1 | ts_col1, ts_val2 | datetime_string2 | ts_col2 [, time_unit]) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：计算两个时间戳之间的差值，并近似到时间单位 time_unit 指定的精度。

**返回结果数据类型**：长整型 INT64。

**应用字段**：UNIX 时间戳，日期时间格式的字符串，或者 TIMESTAMP 类型的列。

**适用于**：表、超级表。

**使用说明**：
- 支持的时间单位 time_unit 如下：
          1u(微秒)，1a(毫秒)，1s(秒)，1m(分)，1h(小时)，1d(天)。
- 如果时间单位 time_unit 未指定， 返回的时间差值精度与当前 DATABASE 设置的时间精度一致。


#### TIMETRUNCATE

```sql
SELECT TIMETRUNCATE(ts_val | datetime_string | ts_col, time_unit) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：将时间戳按照指定时间单位 time_unit 进行截断。

**返回结果数据类型**：TIMESTAMP 时间戳类型。

**应用字段**：UNIX 时间戳，日期时间格式的字符串，或者 TIMESTAMP 类型的列。

**适用于**：表、超级表。

**使用说明**：
- 支持的时间单位 time_unit 如下：
          1u(微秒)，1a(毫秒)，1s(秒)，1m(分)，1h(小时)，1d(天)。
- 返回的时间戳精度与当前 DATABASE 设置的时间精度一致。


#### TIMEZONE

```sql
SELECT TIMEZONE() FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：返回客户端当前时区信息。

**返回结果数据类型**：VARCHAR 类型。

**应用字段**：无

**适用于**：表、超级表。


#### TODAY

```sql
SELECT TODAY() FROM { tb_name | stb_name } [WHERE clause];
SELECT select_expr FROM { tb_name | stb_name } WHERE ts_col cond_operatior TODAY()];
INSERT INTO tb_name VALUES (TODAY(), ...);
```

**功能说明**：返回客户端当日零时的系统时间。

**返回结果数据类型**：TIMESTAMP 时间戳类型。

**应用字段**：在 WHERE 或 INSERT 语句中使用时只能作用于 TIMESTAMP 类型的字段。

**适用于**：表、超级表。

**使用说明**：

- 支持时间加减操作，如 TODAY() + 1s, 支持的时间单位如下：
                b(纳秒)，u(微秒)，a(毫秒)，s(秒)，m(分)，h(小时)，d(天)，w(周)。
- 返回的时间戳精度与当前 DATABASE 设置的时间精度一致。


## 聚合函数

聚合函数为查询结果集的每一个分组返回单个结果行。可以由 GROUP BY 或窗口切分子句指定分组，如果没有，则整个查询结果集视为一个分组。

TDengine 支持针对数据的聚合查询。提供如下聚合函数。

### AVG

```
SELECT AVG(field_name) FROM tb_name [WHERE clause];
```

**功能说明**：统计表/超级表中某列的平均值。

**返回数据类型**：双精度浮点数 Double。

**适用数据类型**：数值类型。

**适用于**：表、超级表。


### COUNT

```
SELECT COUNT([*|field_name]) FROM tb_name [WHERE clause];
```

**功能说明**：统计表/超级表中记录行数或某列的非空值个数。

**返回数据类型**：长整型 INT64。

**适用数据类型**：应用全部字段。

**适用于**：表、超级表。

**使用说明**:

- 可以使用星号(\*)来替代具体的字段，使用星号(\*)返回全部记录数量。
- 针对同一表的（不包含 NULL 值）字段查询结果均相同。
- 如果统计对象是具体的列，则返回该列中非 NULL 值的记录数量。


### ELAPSED

```mysql
SELECT ELAPSED(ts_primary_key [, time_unit]) FROM { tb_name | stb_name } [WHERE clause] [INTERVAL(interval [, offset]) [SLIDING sliding]];
```

**功能说明**：elapsed函数表达了统计周期内连续的时间长度，和twa函数配合使用可以计算统计曲线下的面积。在通过INTERVAL子句指定窗口的情况下，统计在给定时间范围内的每个窗口内有数据覆盖的时间范围；如果没有INTERVAL子句，则返回整个给定时间范围内的有数据覆盖的时间范围。注意，ELAPSED返回的并不是时间范围的绝对值，而是绝对值除以time_unit所得到的单位个数。

**返回结果类型**：Double

**适用数据类型**：Timestamp类型

**支持的版本**：2.6.0.0 及以后的版本。

**适用于**: 表，超级表，嵌套查询的外层查询

**说明**：
- field_name参数只能是表的第一列，即timestamp主键列。
- 按time_unit参数指定的时间单位返回，最小是数据库的时间分辨率。time_unit参数未指定时，以数据库的时间分辨率为时间单位。
- 可以和interval组合使用，返回每个时间窗口的时间戳差值。需要特别注意的是，除第一个时间窗口和最后一个时间窗口外，中间窗口的时间戳差值均为窗口长度。
- order by asc/desc不影响差值的计算结果。
- 对于超级表，需要和group by tbname子句组合使用，不可以直接使用。
- 对于普通表，不支持和group by子句组合使用。
- 对于嵌套查询，仅当内层查询会输出隐式时间戳列时有效。例如select elapsed(ts) from (select diff(value) from sub1)语句，diff函数会让内层查询输出隐式时间戳列，此为主键列，可以用于elapsed函数的第一个参数。相反，例如select elapsed(ts) from (select * from sub1) 语句，ts列输出到外层时已经没有了主键列的含义，无法使用elapsed函数。此外，elapsed函数作为一个与时间线强依赖的函数，形如select elapsed(ts) from (select diff(value) from st group by tbname)尽管会返回一条计算结果，但并无实际意义，这种用法后续也将被限制。
- 不支持与leastsquares、diff、derivative、top、bottom、last_row、interp等函数混合使用。

### LEASTSQUARES

```
SELECT LEASTSQUARES(field_name, start_val, step_val) FROM tb_name [WHERE clause];
```

**功能说明**：统计表中某列的值是主键（时间戳）的拟合直线方程。start_val 是自变量初始值，step_val 是自变量的步长值。

**返回数据类型**：字符串表达式（斜率, 截距）。

**适用数据类型**：field_name 必须是数值类型。

**适用于**：表。


### MODE

```
SELECT MODE(field_name) FROM tb_name [WHERE clause];
```

**功能说明**：返回出现频率最高的值，若存在多个频率相同的最高值，输出空。

**返回数据类型**：同应用的字段。

**适用数据类型**： 数值类型。

**适用于**：表和超级表。


### SPREAD

```
SELECT SPREAD(field_name) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：统计表/超级表中某列的最大值和最小值之差。

**返回数据类型**：双精度浮点数。

**适用数据类型**：数值类型或TIMESTAMP类型。

**适用于**：表和超级表。


### STDDEV

```
SELECT STDDEV(field_name) FROM tb_name [WHERE clause];
```

**功能说明**：统计表中某列的均方差。

**返回数据类型**：双精度浮点数 Double。

**适用数据类型**：数值类型。

**适用于**：表和超级表。


### SUM

```
SELECT SUM(field_name) FROM tb_name [WHERE clause];
```

**功能说明**：统计表/超级表中某列的和。

**返回数据类型**：双精度浮点数 Double 和长整型 INT64。

**适用数据类型**：数值类型。

**适用于**：表和超级表。


### HYPERLOGLOG

```
SELECT HYPERLOGLOG(field_name) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：
  - 采用 hyperloglog 算法，返回某列的基数。该算法在数据量很大的情况下，可以明显降低内存的占用，但是求出来的基数是个估算值，标准误差（标准误差是多次实验，每次的平均数的标准差，不是与真实结果的误差）为 0.81%。
  - 在数据量较少的时候该算法不是很准确，可以使用 select count(data) from (select unique(col) as data from table) 的方法。

**返回结果类型**：整形。

**适用数据类型**：任何类型。

**适用于**：表和超级表。


### HISTOGRAM

```
SELECT HISTOGRAM(field_name，bin_type, bin_description, normalized) FROM tb_name [WHERE clause];
```

**功能说明**：统计数据按照用户指定区间的分布。

**返回结果类型**：如归一化参数 normalized 设置为 1，返回结果为双精度浮点类型 DOUBLE，否则为长整形 INT64。

**适用数据类型**：数值型字段。

**适用于**: 表和超级表。

**详细说明**：
1. bin_type 用户指定的分桶类型, 有效输入类型为"user_input“, ”linear_bin", "log_bin"。
2. bin_description 描述如何生成分桶区间，针对三种桶类型，分别为以下描述格式(均为 JSON 格式字符串)：       
    - "user_input": "[1, 3, 5, 7]" 
       用户指定 bin 的具体数值。
       
    - "linear_bin": "{"start": 0.0, "width": 5.0, "count": 5, "infinity": true}"
       "start" 表示数据起始点，"width" 表示每次 bin 偏移量, "count" 为 bin 的总数，"infinity" 表示是否添加（-inf, inf）作为区间起点跟终点，
       生成区间为[-inf, 0.0, 5.0, 10.0, 15.0, 20.0, +inf]。
 
    - "log_bin": "{"start":1.0, "factor": 2.0, "count": 5, "infinity": true}"
       "start" 表示数据起始点，"factor" 表示按指数递增的因子，"count" 为 bin 的总数，"infinity" 表示是否添加（-inf, inf）作为区间起点跟终点，
       生成区间为[-inf, 1.0, 2.0, 4.0, 8.0, 16.0, +inf]。
3. normalized 是否将返回结果归一化到 0~1 之间 。有效输入为 0 和 1。


## 选择函数

选择函数根据语义在查询结果集中选择一行或多行结果返回。用户可以同时指定输出 ts 列或其他列（包括 tbname 和标签列），这样就可以方便地知道被选出的值是源于哪个数据行的。

### APERCENTILE

```
SELECT APERCENTILE(field_name, P[, algo_type])
FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：统计表/超级表中指定列的值的近似百分比分位数，与 PERCENTILE 函数相似，但是返回近似结果。

**返回数据类型**： 双精度浮点数 Double。

**适用数据类型**：数值类型。P值范围是[0,100]，当为0时等同于MIN，为100时等同于MAX。如果不指定 algo_type 则使用默认算法 。

**适用于**：表、超级表。

### BOTTOM

```
SELECT BOTTOM(field_name, K) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：统计表/超级表中某列的值最小 _k_ 个非 NULL 值。如果多条数据取值一样，全部取用又会超出 k 条限制时，系统会从相同值中随机选取符合要求的数量返回。

**返回数据类型**：同应用的字段。

**适用数据类型**：数值类型。

**适用于**：表和超级表。

**使用说明**:

- *k*值取值范围 1≤*k*≤100；
- 系统同时返回该记录关联的时间戳列；
- 限制：BOTTOM 函数不支持 FILL 子句。

### FIRST

```
SELECT FIRST(field_name) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：统计表/超级表中某列的值最先写入的非 NULL 值。

**返回数据类型**：同应用的字段。

**适用数据类型**：所有字段。

**适用于**：表和超级表。

**使用说明**:

- 如果要返回各个列的首个（时间戳最小）非 NULL 值，可以使用 FIRST(\*)；
- 如果结果集中的某列全部为 NULL 值，则该列的返回结果也是 NULL；
- 如果结果集中所有列全部为 NULL 值，则不返回结果。

### INTERP

```
SELECT INTERP(field_name) FROM { tb_name | stb_name } [WHERE where_condition] [ RANGE(timestamp1,timestamp2) ] [EVERY(interval)] [FILL ({ VALUE | PREV | NULL | LINEAR | NEXT})];
```

**功能说明**：返回指定时间截面指定列的记录值或插值。

**返回数据类型**：同字段类型。

**适用数据类型**：数值类型。

**适用于**：表、超级表。

**使用说明**

- INTERP 用于在指定时间断面获取指定列的记录值，如果该时间断面不存在符合条件的行数据，那么会根据 FILL 参数的设定进行插值。
- INTERP 的输入数据为指定列的数据，可以通过条件语句（where 子句）来对原始列数据进行过滤，如果没有指定过滤条件则输入为全部数据。
- INTERP 的输出时间范围根据 RANGE(timestamp1,timestamp2)字段来指定，需满足 timestamp1<=timestamp2。其中 timestamp1（必选值）为输出时间范围的起始值，即如果 timestamp1 时刻符合插值条件则 timestamp1 为输出的第一条记录，timestamp2（必选值）为输出时间范围的结束值，即输出的最后一条记录的 timestamp 不能大于 timestamp2。如果没有指定 RANGE，那么满足过滤条件的输入数据中第一条记录的 timestamp 即为 timestamp1，最后一条记录的 timestamp 即为 timestamp2，同样也满足 timestamp1 <= timestamp2。
- INTERP 根据 EVERY 字段来确定输出时间范围内的结果条数，即从 timestamp1 开始每隔固定长度的时间（EVERY 值）进行插值。如果没有指定 EVERY，则默认窗口大小为无穷大，即从 timestamp1 开始只有一个窗口。
- INTERP 根据 FILL 字段来决定在每个符合输出条件的时刻如何进行插值，如果没有 FILL 字段则默认不插值，即输出为原始记录值或不输出（原始记录不存在）。
- INTERP 只能在一个时间序列内进行插值，因此当作用于超级表时必须跟 group by tbname 一起使用，当作用嵌套查询外层时内层子查询不能含 GROUP BY 信息。
- INTERP 的插值结果不受 ORDER BY timestamp 的影响，ORDER BY timestamp 只影响输出结果的排序。

### LAST

```
SELECT LAST(field_name) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：统计表/超级表中某列的值最后写入的非 NULL 值。

**返回数据类型**：同应用的字段。

**适用数据类型**：所有字段。

**适用于**：表和超级表。

**使用说明**:

- 如果要返回各个列的最后（时间戳最大）一个非 NULL 值，可以使用 LAST(\*)；
- 如果结果集中的某列全部为 NULL 值，则该列的返回结果也是 NULL；如果结果集中所有列全部为 NULL 值，则不返回结果。
- 在用于超级表时，时间戳完全一样且同为最大的数据行可能有多个，那么会从中随机返回一条，而并不保证多次运行所挑选的数据行必然一致。


### LAST_ROW

```
SELECT LAST_ROW(field_name) FROM { tb_name | stb_name };
```

**功能说明**：返回表/超级表的最后一条记录。

**返回数据类型**：同应用的字段。

**适用数据类型**：所有字段。

**适用于**：表和超级表。

**使用说明**：

- 在用于超级表时，时间戳完全一样且同为最大的数据行可能有多个，那么会从中随机返回一条，而并不保证多次运行所挑选的数据行必然一致。
- 不能与 INTERVAL 一起使用。

### MAX

```
SELECT MAX(field_name) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：统计表/超级表中某列的值最大值。

**返回数据类型**：同应用的字段。

**适用数据类型**：数值类型。

**适用于**：表和超级表。


### MIN

```
SELECT MIN(field_name) FROM {tb_name | stb_name} [WHERE clause];
```

**功能说明**：统计表/超级表中某列的值最小值。

**返回数据类型**：同应用的字段。

**适用数据类型**：数值类型。

**适用于**：表和超级表。


### PERCENTILE

```
SELECT PERCENTILE(field_name, P) FROM { tb_name } [WHERE clause];
```

**功能说明**：统计表中某列的值百分比分位数。

**返回数据类型**： 双精度浮点数 Double。

**应用字段**：数值类型。

**适用于**：表。

**使用说明**：*P*值取值范围 0≤*P*≤100，为 0 的时候等同于 MIN，为 100 的时候等同于 MAX。


### TAIL

```
SELECT TAIL(field_name, k, offset_val) FROM {tb_name | stb_name} [WHERE clause];
```

**功能说明**：返回跳过最后 offset_val 个，然后取连续 k 个记录，不忽略 NULL 值。offset_val 可以不输入。此时返回最后的 k 个记录。当有 offset_val 输入的情况下，该函数功能等效于 `order by ts desc LIMIT k OFFSET offset_val`。

**参数范围**：k: [1,100] offset_val: [0,100]。

**返回数据类型**：同应用的字段。

**适用数据类型**：适合于除时间主列外的任何类型。

**适用于**：表、超级表。


### TOP

```
SELECT TOP(field_name, K) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**： 统计表/超级表中某列的值最大 _k_ 个非 NULL 值。如果多条数据取值一样，全部取用又会超出 k 条限制时，系统会从相同值中随机选取符合要求的数量返回。

**返回数据类型**：同应用的字段。

**适用数据类型**：数值类型。

**适用于**：表、超级表。

**使用说明**:

- *k*值取值范围 1≤*k*≤100；
- 系统同时返回该记录关联的时间戳列；
- 限制：TOP 函数不支持 FILL 子句。

### UNIQUE

```
SELECT UNIQUE(field_name) FROM {tb_name | stb_name} [WHERE clause];
```

**功能说明**：返回该列的数值首次出现的值。该函数功能与 distinct 相似，但是可以匹配标签和时间戳信息。可以针对除时间列以外的字段进行查询，可以匹配标签和时间戳，其中的标签和时间戳是第一次出现时刻的标签和时间戳。

**返回数据类型**：同应用的字段。

**适用数据类型**：适合于除时间类型以外的字段。

**适用于**: 表和超级表。


## 时序数据特有函数

时序数据特有函数是 TDengine 为了满足时序数据的查询场景而量身定做出来的。在通用数据库中，实现类似功能通常需要复杂的查询语法，且效率很低。TDengine 以函数的方式内置了这些功能，最大程度的减轻了用户的使用成本。

### CSUM

```sql
    SELECT CSUM(field_name) FROM { tb_name | stb_name } [WHERE clause]
```

**功能说明**：累加和（Cumulative sum），输出行与输入行数相同。

**返回结果类型**： 输入列如果是整数类型返回值为长整型 （int64_t），浮点数返回值为双精度浮点数（Double）。无符号整数类型返回值为无符号长整型（uint64_t）。 返回结果中同时带有每行记录对应的时间戳。

**适用数据类型**：数值类型。

**嵌套子查询支持**： 适用于内层查询和外层查询。

**适用于**：表和超级表

**使用说明**： 
  
  - 不支持 +、-、*、/ 运算，如 csum(col1) + csum(col2)。
  - 只能与聚合（Aggregation）函数一起使用。 该函数可以应用在普通表和超级表上。 
  - 使用在超级表上的时候，需要搭配 Group by tbname使用，将结果强制规约到单个时间线。


### DERIVATIVE

```
SELECT DERIVATIVE(field_name, time_interval, ignore_negative) FROM tb_name [WHERE clause];
```

**功能说明**：统计表中某列数值的单位变化率。其中单位时间区间的长度可以通过 time_interval 参数指定，最小可以是 1 秒（1s）；ignore_negative 参数的值可以是 0 或 1，为 1 时表示忽略负值。

**返回数据类型**：双精度浮点数。

**适用数据类型**：数值类型。

**适用于**：表、超级表

**使用说明**: DERIVATIVE 函数可以在由 GROUP BY 划分出单独时间线的情况下用于超级表（也即 GROUP BY tbname）。


### DIFF

  ```sql
  SELECT {DIFF(field_name, ignore_negative) | DIFF(field_name)} FROM tb_name [WHERE clause];
  ```

**功能说明**：统计表中某列的值与前一行对应值的差。 ignore_negative 取值为 0|1 , 可以不填，默认值为 0. 不忽略负值。ignore_negative 为 1 时表示忽略负数。

**返回数据类型**：同应用字段。

**适用数据类型**：数值类型。

**适用于**：表、超级表。

**使用说明**: 输出结果行数是范围内总行数减一，第一行没有结果输出。


### IRATE

```
SELECT IRATE(field_name) FROM tb_name WHERE clause;
```

**功能说明**：计算瞬时增长率。使用时间区间中最后两个样本数据来计算瞬时增长速率；如果这两个值呈递减关系，那么只取最后一个数用于计算，而不是使用二者差值。

**返回数据类型**：双精度浮点数 Double。

**适用数据类型**：数值类型。

**适用于**：表、超级表。

### MAVG

```sql
    SELECT MAVG(field_name, K) FROM { tb_name | stb_name } [WHERE clause]
```

  **功能说明**： 计算连续 k 个值的移动平均数（moving average）。如果输入行数小于 k，则无结果输出。参数 k 的合法输入范围是 1≤ k ≤ 1000。

  **返回结果类型**： 返回双精度浮点数类型。

  **适用数据类型**： 数值类型。

  **嵌套子查询支持**： 适用于内层查询和外层查询。

  **适用于**：表和超级表

  **使用说明**： 
  
  - 不支持 +、-、*、/ 运算，如 mavg(col1, k1) + mavg(col2, k1); 
  - 只能与普通列，选择（Selection）、投影（Projection）函数一起使用，不能与聚合（Aggregation）函数一起使用；
  - 使用在超级表上的时候，需要搭配 Group by tbname使用，将结果强制规约到单个时间线。

### SAMPLE

```sql
    SELECT SAMPLE(field_name, K) FROM { tb_name | stb_name } [WHERE clause]
```

  **功能说明**： 获取数据的 k 个采样值。参数 k 的合法输入范围是 1≤ k ≤ 1000。

  **返回结果类型**： 同原始数据类型， 返回结果中带有该行记录的时间戳。

  **适用数据类型**： 在超级表查询中使用时，不能应用在标签之上。

  **嵌套子查询支持**： 适用于内层查询和外层查询。

  **适用于**：表和超级表

  **使用说明**： 
  
  - 不能参与表达式计算；该函数可以应用在普通表和超级表上；
  - 使用在超级表上的时候，需要搭配 Group by tbname 使用，将结果强制规约到单个时间线。

### STATECOUNT

```
SELECT STATECOUNT(field_name, oper, val) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：返回满足某个条件的连续记录的个数，结果作为新的一列追加在每行后面。条件根据参数计算，如果条件为 true 则加 1，条件为 false 则重置为-1，如果数据为 NULL，跳过该条数据。

**参数范围**：

- oper : LT (小于)、GT（大于）、LE（小于等于）、GE（大于等于）、NE（不等于）、EQ（等于），不区分大小写。
- val : 数值型

**返回结果类型**：整形。

**适用数据类型**：数值类型。

**嵌套子查询支持**：不支持应用在子查询上。

**适用于**：表和超级表。

**使用说明**：

- 该函数可以应用在普通表上，在由 GROUP BY 划分出单独时间线的情况下用于超级表（也即 GROUP BY tbname）
- 不能和窗口操作一起使用，例如 interval/state_window/session_window。


### STATEDURATION

```sql
SELECT stateDuration(field_name, oper, val, unit) FROM { tb_name | stb_name } [WHERE clause];
```

**功能说明**：返回满足某个条件的连续记录的时间长度，结果作为新的一列追加在每行后面。条件根据参数计算，如果条件为 true 则加上两个记录之间的时间长度（第一个满足条件的记录时间长度记为 0），条件为 false 则重置为-1，如果数据为 NULL，跳过该条数据。

**参数范围**：

- oper : LT (小于)、GT（大于）、LE（小于等于）、GE（大于等于）、NE（不等于）、EQ（等于），不区分大小写。
- val : 数值型
- unit : 时间长度的单位，范围[1s、1m、1h ]，不足一个单位舍去。默认为 1s。

**返回结果类型**：整形。

**适用数据类型**：数值类型。

**嵌套子查询支持**：不支持应用在子查询上。

**适用于**：表和超级表。

**使用说明**：

- 该函数可以应用在普通表上，在由 GROUP BY 划分出单独时间线的情况下用于超级表（也即 GROUP BY tbname）
- 不能和窗口操作一起使用，例如 interval/state_window/session_window。


### TWA

```
SELECT TWA(field_name) FROM tb_name WHERE clause;
```

**功能说明**：时间加权平均函数。统计表中某列在一段时间内的时间加权平均。

**返回数据类型**：双精度浮点数 Double。

**适用数据类型**：数值类型。

**适用于**：表、超级表。

**使用说明**： TWA 函数可以在由 GROUP BY 划分出单独时间线的情况下用于超级表（也即 GROUP BY tbname）。


## 系统信息函数

### DATABASE

```
SELECT DATABASE();
```

**说明**：返回当前登录的数据库。如果登录的时候没有指定默认数据库，且没有使用USE命令切换数据库，则返回NULL。


### CLIENT_VERSION

```
SELECT CLIENT_VERSION();
```

**说明**：返回客户端版本。

### SERVER_VERSION

```
SELECT SERVER_VERSION();
```

**说明**：返回服务端版本。

### SERVER_STATUS

```
SELECT SERVER_VERSION();
```

**说明**：返回服务端当前的状态。