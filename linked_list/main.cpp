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
		cout << "현재 리스트 ::" ;print_all(li);
		command = get_command();
		
		//커맨드 실행

		if (command == 0)
			return 0;//종료
		
		else if (command == 1)
		{
			cout << endl << "추가할 값 : ";
			cin >> temp1;
			insert(li, temp1);
			cout << endl << "성공적으로 추가하였습니다." << endl;
		
		}
		else if (command == 2)
		{
			cout << endl << "삭제할 값 : ";
			cin >> temp1;
			if (remove(li, temp1))
				cout << endl << "성공적으로 삭제하였습니다." << endl;
			else
				cout << endl << "삭제에 실패하였습니다." << endl;

		}
		else if (command == 3)
		{
			cout << endl << "삭제할 위치 : ";
			cin >> temp1;
			if (remove_at(li, temp1))
				cout << endl << "성공적으로 삭제하였습니다." << endl;
			else
				cout << endl << "삭제에 실패하였습니다." << endl;
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
			cout << endl << "잘못된 입력." << endl;
		}
		
		cout << endl << endl;

	}

	return 0;
}

//커맨드 받는 함수
int get_command()
{
	int command;
	//Menu 출력 및 커맨드 입력

	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ"<< endl;
	cout << "1. 추가" << endl;
	cout << "2. 제거(숫자로)" << endl;
	cout << "3. 제거(인덱스로)" << endl;
	cout << "5. 파일로 저장(언제든지가능)" << endl;
	cout << "6. 파일에서 불러오기(언제든지가능,기존존재하면 기존껀 파일로 저장)" << endl;
	cout << "0. 종료" << endl;
	cout << "ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ" << endl;
	cout << "입력 ::";
	cin >> command;
	cout << endl;

	return command;

}