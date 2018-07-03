#include"LinkedList.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int get_command();

int main(void)
{
	int command, temp1;
	string file = "file.txt";
	List li;
	
	while (true)
	{
		cout << "���� ����Ʈ ::" ;print_all(li);
		command = get_command();
		
		//Ŀ�ǵ� ����

		if (command == 0)
			return 0;//����
		
		else if (command == 1)
		{
			cout << endl << "�߰��� �� : ";
			cin >> temp1;
			insert(li, temp1);
			cout << endl << "���������� �߰��Ͽ����ϴ�." << endl;
		
		}
		else if (command == 2)
		{
			cout << endl << "������ �� : ";
			cin >> temp1;
			if (remove(li, temp1))
				cout << endl << "���������� �����Ͽ����ϴ�." << endl;
			else
				cout << endl << "������ �����Ͽ����ϴ�." << endl;

		}
		else if (command == 3)
		{
			cout << endl << "������ ��ġ : ";
			cin >> temp1;
			if (remove_at(li, temp1))
				cout << endl << "���������� �����Ͽ����ϴ�." << endl;
			else
				cout << endl << "������ �����Ͽ����ϴ�." << endl;
		}
		else if (command == 5)
		{

			
			
			ofstream writeFile(file.data());
			if (writeFile.is_open())
			{
				Node* temp = li.head;
				while (temp != nullptr)
				{
					writeFile << temp->val;
					if (temp->next != nullptr)
						writeFile << " ";
					temp = temp->next;
				}
				
				writeFile.close();

			}
			
		}
		else if (command == 6)
		{
			while (li.length != 0)
			{
				remove_at(li, 0);
			}
			ifstream openFile(file.data());
			if (openFile.is_open()) 
			{
				int line;
				while (!openFile.eof())
				{
					openFile >> line;
					insert(li, line);
				}
			
			}
			openFile.close();

			
		}
		else
		{
			cout << endl << "�߸��� �Է�." << endl;
		}
		
		cout << endl << endl;

	}

	return 0;
}

//Ŀ�ǵ� �޴� �Լ�
int get_command()
{
	int command;
	//Menu ��� �� Ŀ�ǵ� �Է�

	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�"<< endl;
	cout << "1. �߰�" << endl;
	cout << "2. ����(���ڷ�)" << endl;
	cout << "3. ����(�ε�����)" << endl;
	cout << "5. ���Ϸ� ����(������������)" << endl;
	cout << "6. ���Ͽ��� �ҷ�����(������������,���������ϸ� ������ ���Ϸ� ����)" << endl;
	cout << "0. ����" << endl;
	cout << "�ѤѤѤѤѤѤѤѤѤѤѤѤѤѤ�" << endl;
	cout << "�Է� ::";
	cin >> command;
	cout << endl;

	return command;

}