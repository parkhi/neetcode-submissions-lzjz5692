class Solution {
public:
    int compress(vector<char>& chars) {

        int read=0, write=0, curlen=0, finalen = 0;
        char curchar;

        if(chars.size() == 1) {
            return 1;
        }

        while(read < chars.size()) {
            curlen = 1;
            curchar = chars[read];

            //cout <<"curchar read "<<curchar<<" "<<read<<endl; 

            while((read < chars.size()-1) && (chars[read] == chars[read+1])) {
                curlen++;
                read++;
                //cout << "curlen and curchar "<<curlen<<" "<<curchar<<endl;
            }
            if(read < chars.size()) {
                read++;
            }
            chars[write] = curchar;
            write++;
            
            if(curlen > 1) {

                string temp = to_string(curlen);
                //cout<< "temp is " <<temp<<endl;

                for( int k = 0; k<temp.length(); k++) {

                    chars[write++] = temp[k];
                    //cout<<"chars[write] "<<chars[write-1]<<endl;
                } 
            }
        }

        return write;
        
    }
};