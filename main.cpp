#include <iostream>
#include <string>
#include <vector>

using namespace std;

////////////////////////////////////////////////

class block
{
public:
    block(string name);
	string get_name(){ return name;}
	int get_val(){ return val;}

private:
    string name;
    int val;
};

block::block(string name)
:name(name)
,val(0)
{
}

////////////////////////////////////////////////

void show_blocks(vector<block> &list_blocks)
{
	system("clear");

	cout << "list blocks:" << endl;

	for(int i = 0; i < list_blocks.size(); i++)
	{
		cout << "id: " << i + 1;
		cout << "	";
		cout << "name: " << list_blocks[i].get_name();
		cout << "	";
		cout << "val: " << list_blocks[i].get_val();
		cout << endl;
	}
}

void delete_block(vector<block> &list_blocks)
{
	int input;
	show_blocks(list_blocks);

	while(true)
	{
		cout << endl;
		cout << "input id block for deleted: " << endl;
		cin >> input;
		if(input >= 1 and input <= list_blocks.size())
		{
			list_blocks.erase(list_blocks.begin() + (input - 1));
			cout << "block is deleted" << endl;
			break;
		}
		else
			cout << "input number is not correct" << endl;
	}	
}

void add_block(vector<block> &list_blocks, string name)
{
	list_blocks.push_back(block(name));
}

////////////////////////////////////////////////

int main()
{
    vector<block> list_blocks;
	
	add_block(list_blocks, "food");	
	add_block(list_blocks, "funny");	

	show_blocks(list_blocks);
	delete_block(list_blocks);

    return 0;
}