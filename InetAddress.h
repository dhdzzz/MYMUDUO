#pragma once
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string>


// 封装socket地址类型（地址转换）
class InetAddress{
public:
    // 设置端口号和地址
    explicit InetAddress(uint16_t port = 0, std::string ip = "127.0.0.1");
    explicit InetAddress(const sockaddr_in& addr)
        : addr_(addr)
    {}

    std::string toIp() const;
    std::string toIpPort() const;
    uint16_t toPort() const;

    const sockaddr_in* getSockAddr() const {return &addr_;}
    void setSockAddr(const sockaddr_in & addr) { addr_ = addr; }
private:
    sockaddr_in addr_;
};