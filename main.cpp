#include "BPlusTree.h"
size_t Delay::time = 0;

void Test1(BPlusTree* pTree, int count)
{
    Delay::initialize();
    int i = 0;
    while (i < count)
    {
        //srand( (unsigned)time( NULL ) );//这是一个种子，如果不要随机功能，请把此句话注释掉
        int x = rand() % 999 + 1;
        if (pTree->Insert(x))
            ++i;
    }
    cout << "successed!" << endl;
    if(Delay::time)
        Delay::print();
}

// 在树中查找某数据
void Test2(BPlusTree* pTree, int data)
{
    Delay::initialize();

    (void)pTree->Search(data, true);
    cout << endl;
    if(Delay::time)
        Delay::print();
}

// 在树中插入某数据
void Test3(BPlusTree* pTree, int data)
{
    Delay::initialize();
    bool success = pTree->Insert(data);
    if (true == success)
    {
    cout << "successed!" << endl;
    }
    else
    {
    cout << "failed!" << endl;
    }
    if(Delay::time)
        Delay::print();
}

// 在树中删除某数据
void Test4(BPlusTree* pTree, int data)
{
    Delay::initialize();
    bool success = pTree->Delete(data);
    if (true == success)
    {
    cout << "successed!" << endl;
    }
    else
    {
    cout << "failed!" << endl;
    }
    if(Delay::time)
        Delay::print();
}


// 打印
void Test5(BPlusTree* pTree)
{
    pTree->PrintTree();
}

// 对树进行检查
void Test6(BPlusTree* pTree)
{
    bool success = pTree->CheckTree();
    if (true == success)
    {
    cout << "successed!" << endl;

    }
    else
    {
    cout << "failed!" << endl;
    }
}
void Test7(BPlusTree *pTree)
{
    pTree->ClearTree();
    cout << "successed!" << endl;
}

int main(int argc, char* argv[])
{
    BPlusTree* pTree = new BPlusTree;

    int x = 1;
    int y = 0;
    while (0 != x)
    {
        cout << endl;
        cout << "    *******************************************************************" << endl;
        cout << "    * There is a B+ Tree which is empty, what do you want to do?      *" << endl;
        cout << "    *               1:Insert some random numbers                      *" << endl;
        cout << "    *               2:Search a number                                 *" << endl;
        cout << "    *               3:Insert a number                                 *" << endl;
        cout << "    *               4:Delete a number                                 *" << endl;
        cout << "    *               5:Print the tree                                  *" << endl; 
        cout << "    *               6:Check the tree                                  *" << endl; 
        cout << "    *               7:Clear the tree                                  *" << endl; 
        cout << "    *               0:Exit                                            *" << endl;
        cout << "    *******************************************************************" << endl;
        cout << "Your choice:" << endl;

        cin >> x;
        switch (x)
        {
        case 1:
            cout << "How many random numbers do you want to insert?" << endl;
            cin >> y;
            Test1(pTree, y);
            break;
       
        case 2:
            cout << "Please enter the number you want to search:" << endl;
            cin >> y;
            Test2(pTree, y);
            break;

        case 3:
            cout << "Please enter the number you want to insert:" << endl;
            cin >> y;
            Test3(pTree, y);
            break;

        case 4:
            cout << "Please enter the number you want to delete:" << endl;
            cin >> y;
            Test4(pTree, y);
            break;

        case 5:
            Test5(pTree);
            break;

        case 6:
            Test6(pTree);
            break;
        case 7:
            Test7(pTree);
            break;
        case 0:
            delete pTree;
            return 0;
            break;

        default:
            cout << endl;
            cout << "Invalid choice, please try again." << endl;
            break;
        }
    }

    delete pTree;
    return 0;
}