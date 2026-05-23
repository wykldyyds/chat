#ifndef CHATSERVICE_H
#define CHATSERVICE_H

#include "json.hpp"
#include <muduo/net/TcpConnection.h>
#include <muduo/net/EventLoop.h>
using namespace muduo;
using namespace muduo::net;
#include <unordered_map>
#include <functional>
using namespace std;
using namespace placeholders;
using json = nlohmann::json;

// 消息id和其对应的业务处理方法
using MsgHandler = function<void(const TcpConnectionPtr &conn, json &js, Timestamp)>;

//聊天服务器业务类
class ChatService
{
public:

    // 获取单例对象的接口函数
    static ChatService* instance();

    // 处理登录业务
    void login(const TcpConnectionPtr &conn, json &js, Timestamp time);

    // 处理注册业务
    void reg(const TcpConnectionPtr &conn, json &js, Timestamp time);

    // 获取消息id和其对应的业务处理方法
    MsgHandler getHandler(int msgid);


private:
    ChatService();
    // 存储消息id和其对应的业务处理方法
    unordered_map<int, MsgHandler> _msgHandlerMap;

};


#endif