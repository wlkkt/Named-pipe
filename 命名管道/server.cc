/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-12 13:59:38
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-12 18:42:19
 * @FilePath: /2024.5.8/home/ubuntu/2024.5.12/sever.cpp
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "namedPipe.hpp"

 // server read: ���������ܵ���������������
int main()
{
    NamePiped fifo(comm_path, Creater);
    // ���ڶ��˶���,������Ǵ��ļ�������д��û�����һ�������open�����У�ֱ���Է���
    // ����ͬ��
    if (fifo.OpenForRead()) // ������д��ʽ�򿪹ܵ�����
    {
        std::cout << "server open named pipe done" << std::endl;

        sleep(3);
        while (true) // ѭ��д������
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