#include<iostream>
#include<math.h>
#include<stdio.h>
#include<iomanip>
#include<vector>
using namespace std;

string multiply(string num1, string num2)
{
    int n1 = num1.size();
    int n2 = num2.size();
    if (n1 == 0 || n2 == 0)
       return "0";
 
    // will keep the result number in vector
    // in reverse order
    vector<int> result(n1 + n2, 0);
 
    // Below two indexes are used to find positions
    // in result. 
    int i_n1 = 0; 
    int i_n2 = 0; 
 
    // Go from right to left in num1
    for (int i=n1-1; i>=0; i--)
    {
        int carry = 0;
        int n1 = num1[i] - '0';
 
        // To shift position to left after every
        // multiplication of a digit in num2
        i_n2 = 0; 
         
        // Go from right to left in num2             
        for (int j=n2-1; j>=0; j--)
        {
            // Take current digit of second number
            int n2 = num2[j] - '0';
 
            // Multiply with current digit of first number
            // and add result to previously stored result
            // at current position. 
            int sum = n1*n2 + result[i_n1 + i_n2] + carry;
 
            // Carry for next iteration
            carry = sum/10;
 
            // Store result
            result[i_n1 + i_n2] = sum % 10;
 
            i_n2++;
        }
 
        // store carry in next cell
        if (carry > 0)
            result[i_n1 + i_n2] += carry;
 
        // To shift position to left after every
        // multiplication of a digit in num1.
        i_n1++;
    }
 
    // ignore '0's from the right
    int i = result.size() - 1;
    while (i>=0 && result[i] == 0)
       i--;
 
    // If all were '0's - means either both or
    // one of num1 or num2 were '0'
    if (i == -1)
       return "0";
 
    // generate the result string
    string s = "";
    while (i >= 0)
        s += std::to_string(result[i--]);
 
    return s;
}

string area(long double x, long double R)
{
	acos( x/R ) - x*sqrt( 1 - x*x/R/R )/R ;

}

int main()
{
	cout.precision(50);
	string PI="31415926535897932384626433832795"; //31

	long double x1,y1,R;
	cin>>x1>>y1>>R;

	long double x2,y2,r;
	cin>>x2>>y2>>r;

	long double d=sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

	if(fabs(x1-x2)<0.000000001 && fabs(y1-y2)<0.000000001)
	{
		if(r>R)
			r=R;
		
		long long temp=r*r;
		string num=multiply(to_string(temp),PI);
		cout<<num.substr(0,num.length()-28)<<"."<<num.substr(num.length()-28)<<endl;

		return 0;
	}	

	if(d>r+R || fabs(-d+r+R)<0.00000000001)
	{
		printf("0.00000000000000000000\n");
		return 0;
	}

	if( R*R - pow((R*R-r*r+d*d)/2/d,2) <0 ) 
	{
		if(r>R)
			r=R;
		long long temp=r*r;
		string num=multiply(to_string(temp),PI);
		cout<<num.substr(0,num.length()-31)<<"."<<num.substr(num.length()-31)<<endl;

		return 0;
	}	 

	string ans1 = area( (R*R-r*r+d*d)/2/d , R );
	string ans2 = area( (-R*R+r*r+d*d)/2/d , r );
	
	cout<<ans1<<endl<<ans2<<endl;
}