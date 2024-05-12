/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-12 13:57:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-12 19:38:19
 * @FilePath: /2024.5.8/home/ubuntu/2024.5.12/client.cc
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "namedPipe.hpp"

 // write
int main()
{
    NamePiped fifo(comm_path, User); // 管道的使用者
    if (fifo.OpenForWrite())         // 调用以写方式打开管道函数
    {
        std::cout << "client open namd pipe done" << std::endl; // 客户端持续输入
        while (true)
        {
            std::cout << "Please Enter> ";
            std::string message;
            std::getline(std::cin, message); // 将获取的命令行字符串作为message写入管道
            fifo.WriteNamedPipe(message);
        }
    }

    return 0;
}