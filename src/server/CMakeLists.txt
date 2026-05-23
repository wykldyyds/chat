# # 定义类一个SRC_LIST变量，用于存储当前目录下的所有源文件

# 自动搜集当前目录所有 .cpp 文件
aux_source_directory(. SRC_LIST)
aux_source_directory(./db DB_LIST)

# 生成可执行文件（正确写法）
add_executable(ChatServer ${SRC_LIST} ${DB_LIST})

# 指定可执行文件链接时需要依赖的库文件
target_link_libraries(ChatServer muduo_net muduo_base mysqlclient pthread)