#include <iostream>
#include <vector>
#include <list>
#include <fstream>

using namespace std;

typedef vector< list< int > > hashmap;

int hashFunc(int prime, int value)
{
    return value%prime;
}


bool isTwoSum(vector<int> intvec, hashmap hmap, int value, int prime)
{
    for (vector<int>::iterator it = intvec.begin(); it!=intvec.end(); ++it)
    {
        int diff = value-*it;
        if (diff>0)
        {

            list<int> *intlist = &hmap[hashFunc(prime,diff)];
            for (list<int>::iterator lit = (*intlist).begin(); lit!=(*intlist).end(); ++lit)
            {
                if (*lit==diff)
                {
                    return true;
                }
            }
        }
    }

    return false;

}



void printIsTwoSum(vector<int> intvec, hashmap hmap, int value, int prime)
{
    if (isTwoSum(intvec,hmap,value,prime))
    {
        cout << value << " : 1" << endl;
    }
    else
    {
        cout << value << " : 0" << endl;
    }
}

int main()
{
    int prime = 6007;

    vector<int> intvec;
    int i=0;
    ifstream infile("C:\\Documents and Settings\\c\\My Documents\\Downloads\\HashInt.txt");
    while (infile>>i)
    {
        intvec.push_back(i);
        //cout << i << endl;
    }
    cout << intvec.size()  << endl;

    // build hash map
    hashmap hmap(prime);
    for (vector<int>::iterator it = intvec.begin(); it!=intvec.end(); ++it)
    {
        hmap[hashFunc(prime,*it)].push_back(*it);
    }
    int sums[] = {231552,234756,596873,648219,726312,981237,988331,1277361,1283379};
    for (int i=0;i<9;++i)
    {
        printIsTwoSum(intvec,hmap,sums[i],prime);
    }



    return 0;
}
