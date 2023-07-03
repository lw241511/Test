#include "config.h"

int main(int argc, char *argv[])
{
    //需要修改的数据库信息,登录名,密码,库名
    string user = "root";
    string passwd = "lw19981124";
    string databasename = "yourdb";

    //命令行解析
    Config config;
    config.parse_arg(argc, argv);

    WebServer server;
    //cout<<"aaaaaaaa";
    //初始化
    server.init(config.PORT, user, passwd, databasename, config.LOGWrite, 
                config.OPT_LINGER, config.TRIGMode,  config.sql_num,  config.thread_num, 
                config.close_log, config.actor_model);
    

    //日志
    server.log_write();
   // cout<<"baaaaaaa";
    //数据库
    server.sql_pool();
    //cout<<"caaaaaaa";
    //线程池
    server.thread_pool();
    //cout<<"daaaaaaa";
    //触发模式
    server.trig_mode();
    //cout<<"eaaaaaaa";
    //监听
    server.eventListen();
   // cout<<"faaaaaaa";
    //运行
    server.eventLoop();
    //cout<<"gaaaaaaa";
    return 0;
}