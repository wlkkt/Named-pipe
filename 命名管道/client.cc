/*
 * @Author: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @Date: 2024-05-12 13:57:27
 * @LastEditors: error: error: git config user.name & please set dead value or install git && error: git config user.email & please set dead value or install git & please set dead value or install git
 * @LastEditTime: 2024-05-12 19:38:19
 * @FilePath: /2024.5.8/home/ubuntu/2024.5.12/client.cc
 * @Description: ����Ĭ������,������`customMade`, ��koroFileHeader�鿴���� ��������: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
#include "namedPipe.hpp"

 // write
int main()
{
    NamePiped fifo(comm_path, User); // �ܵ���ʹ����
    if (fifo.OpenForWrite())         // ������д��ʽ�򿪹ܵ�����
    {
        std::cout << "client open namd pipe done" << std::endl; // �ͻ��˳�������
        while (true)
        {
            std::cout << "Please Enter> ";
            std::string message;
            std::getline(std::cin, message); // ����ȡ���������ַ�����Ϊmessageд��ܵ�
            fifo.WriteNamedPipe(message);
        }
    }

    return 0;
}