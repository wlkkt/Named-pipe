/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-12 13:59:38
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-12 18:42:19
 * @FilePath: /2024.5.8/home/ubuntu/2024.5.12/sever.cpp
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "namedPipe.hpp"

 // server read: 管理命名管道的整个生命周期
int main()
{
    NamePiped fifo(comm_path, Creater);
    // 对于读端而言,如果我们打开文件，但是写还没来，我会阻塞在open调用中，直到对方打开
    // 进程同步
    if (fifo.OpenForRead()) // 调用以写方式打开管道函数
    {
        std::cout << "server open named pipe done" << std::endl;

        sleep(3);
        while (true) // 循环写入数据
        {
            std::string message;
            int n = fifo.ReadNamedPipe(&message);
            if (n > 0)
            {
                std::cout << "Client Say> " << message << std::endl;
            }
            else if (n == 0)
            {
                std::cout << "Client quit, Server Too!" << std::endl;
                break;
            }
            else
            {
                std::cout << "fifo.ReadNamedPipe Error" << std::endl;
                break;
            }
        }
    }

    return 0;
}