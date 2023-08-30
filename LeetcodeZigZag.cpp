class Solution {
public:

    vector<string>combines(vector<char>rows0,vector<char>rows1,vector<string>rowsString, int numRows) 
    {
        //cout<<"combines,";
        //cout<<"size:"<<rows0.size()<<","<<rows1.size()<<endl;
        for(int i = 0; i<numRows; i++)
        {
            string temp ="";
            if(rows0.at(i)!='\0')
            temp=rows0.at(i);
            if(rows1.at(i)!='\0')
            temp= temp+rows1.at(i); 

            rowsString.at(i)+=temp;        
        }
        /*for(string ss : rowsString)
        {
            cout<<ss;
        }
        cout<<", combines!"<<endl;*/
        return rowsString;
    }

    vector<char> converter1(string s, int i, int subNumRows,int numRows)
    {
       // cout<<"converter1,indexI:"<<i;
        vector<char>rows1;
        rows1.push_back('\0');
        int k = subNumRows-1;
        for(; k>=0;k--)
        {
            //cout<<"LINE32, K"<<k;

            if((i+k)<s.length())
            {
               // cout<<"LINE35,";
                rows1.push_back(s.at(i+k));
            }
            else
            {
                        rows1.push_back('\0');
            }
        }
        rows1.push_back('\0');
        
        //cout<<"converter1!"<<endl;

        return rows1;
    } 

    vector<char>converter0(string s, int i,int numRows) 
    {
       // cout<<"converter0,";

        vector<char>rows0;
        int j =0;
        for(; j<numRows&&(i+j)<s.length(); j++)
        {
            rows0.push_back(s.at(i+j));
        }

        if((i+j)>=s.length())
        while(rows0.size()<=numRows)
        {
            rows0.push_back('\0');
        }
        //cout<<"converter0!"<<endl;

        return rows0;
    }

    string convert(string s, int numRows) 
    {
        if(s.length()==1||numRows==1||numRows>=s.length())
        {
            return s;
        }

        int subNumRows = numRows-2;
        vector<string>rowsString(numRows,"");
        int index = 0;
        
        while(index<s.length())
        {
           // cout<<index<<","<<endl;
            vector<char>temp0 = converter0(s, index, numRows);
            index = index+numRows;

            /*cout<<"temp0:";
            for(char t : temp0)
            {
                cout<<t<<",";
            }
            cout<<"temp0!"<<endl;*/

            
            vector<char>temp1 = converter1(s, index, subNumRows, numRows);
            index = index+subNumRows;
            /*cout<<"temp1:";
            for(char t : temp1)
            {
                cout<<t<<",";
            }
            cout<<"temp1!"<<endl;*/

            rowsString = combines(temp0,temp1,rowsString, numRows); 
        }

        string results="";

        for(int i = 0; i<rowsString.size();i++)
        {
            results+=rowsString.at(i);
        }

       // cout<<"THE END!!"<<endl;
        return results;
    }
};