#include <bits/stdc++.h>
using namespace std;

int prices[] = {10, 23, 12, 15, 14, 19, 56, 15};

class sale
{
    int sales[4][6] = {0};
    int regionTotalSales[4] = {0};

public:
    sale(){};

    /* Read Input */
    void readInp(int regionNo, int salesmanNo, int price)
    {
        sales[regionNo - 1][salesmanNo - 1] += price;
        regionTotalSales[regionNo - 1] += price;
    }

    /* Display Result */
    void display()
    {
        for (int i = 1; i <= 4; i++)
        {
            cout << "\nRegion " << i << "\n";
            for (int j = 1; j <= 6; j++)
            {
                cout << "Salesman " << j << " Rs " << sales[i - 1][j - 1] << "/-\n";
            }
            cout << "Total Sale at Region " << i << " Rs " << regionTotalSales[i - 1] << "/-\n";
        }
    }

    /* Read From File */
    void readFile(string fileName)
    {
        ifstream myfile(fileName);
        string fileContent;
        while (getline(myfile, fileContent))
        {
            int regionNo = 0;
            int i = 0;
            while (fileContent[i] != ' ')
            {
                regionNo = 10 * regionNo + (fileContent[i] - '0');
                i++;
            }
            i++;
            int salesmanNo = 0;
            while (fileContent[i] != ' ')
            {
                salesmanNo = 10 * salesmanNo + (fileContent[i] - '0');
                i++;
            }
            i++;
            int productCode = 0;
            while (fileContent[i] != ' ')
            {
                productCode = 10 * productCode + (fileContent[i] - '0');
                i++;
            }
            i++;
            int productUnit = 0;
            while (fileContent[i] != ' ' && fileContent[i] != '\0')
            {
                productUnit = 10 * productUnit + (fileContent[i] - '0');
                i++;
            }
            int price = prices[productCode - 1] * productUnit;
            this->readInp(regionNo, salesmanNo, price);
        }
    }
};

int main()
{

    sale s1;
    s1.readFile("read.txt");
    s1.display();

    return 0;
}
