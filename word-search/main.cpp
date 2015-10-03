//
//  main.cpp
//  word-search
//
//  Created by Vinod Gupta on 10/1/15.
//  Copyright (c) 2015 vinodg. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool existsInNeighbour(vector<vector<char>>& board, int r,int c,string word,vector<vector<int>>& path){
        if(word.empty())
        {
            return true;
        }
        size_t max_r = board.size();
        size_t max_c = max_r?board[0].size():0;
        
        int next_r = r+1;
        int prev_r = r-1;
        int next_c = c+1;
        int prev_c = c-1;
        
        if((r+1)<max_r && !path[next_r][c] && board[next_r][c]==word[0]){
            path[next_r][c]=1;
            if(existsInNeighbour(board,next_r,c,word.substr(1),path))
                return true;
            path[next_r][c]=0;
        }
        
        if((r-1)>=0 && !path[prev_r][c] && board[prev_r][c]==word[0]){
            path[prev_r][c]=1;
            if(existsInNeighbour(board,prev_r,c,word.substr(1),path))
                return true;
            path[prev_r][c]=0;
        }
        
        if((c+1)<max_c && !path[r][next_c] && board[r][next_c]==word[0]){
            path[r][next_c]=1;
            if(existsInNeighbour(board,r,next_c,word.substr(1),path))
                return true;
            path[r][next_c]=0;
        }
        
        if((c-1)>=0 && !path[r][prev_c] && board[r][prev_c]==word[0]){
            path[r][prev_c]=1;
            if(existsInNeighbour(board,r,prev_c,word.substr(1),path))
                return true;
            path[r][prev_c]=0;
        }
        
        return false;
    }
    
    void printpath(vector<vector<int>>& path)
    {
        for(int i=0;i<path.size();++i)
        {
            for(int j=0;j<path[i].size();++j)
            {
                cout<<path[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        if(word.empty())
        {
            return true;
        }
        vector<vector<int>> path;
        vector<int> row;
        
        size_t max_r = board.size();
        size_t max_c = max_r?board[0].size():0;
        
        for(int c=0;c<max_c;++c)
        {
            row.push_back(0);
        }
        for(int r=0;r<max_r;++r)
        {
            path.push_back(row);
        }
        
        for(int r=0;r<board.size();++r)
        {
            for(int c=0;c<board[r].size();++c)
            {
                if(board[r][c]==word[0]){
                    
                    path[r][c]=1;
                    
                    if(existsInNeighbour(board,r,c,word.substr(1),path))
                    {
                        printpath(path);
                        return true;
                    }
                    path[r][c]=0;
                }
            }
        }
        return false;
    }
    
};

int main(int argc, const char * argv[]) {
    Solution obj;
    
    vector<vector<char>> board;
    vector<char> r1 = {'a','a','a'};
    vector<char> r2 = {'a','b','b'};
    vector<char> r3 = {'a','b','b'};
    vector<char> r4 = {'b','b','b'};
    vector<char> r5 = {'b','b','b'};
    vector<char> r6 = {'a','a','a'};
    vector<char> r7 = {'b','b','b'};
    vector<char> r8 = {'a','b','b'};
    vector<char> r9 = {'a','a','b'};
    vector<char> r10 = {'a','b','a'};
    board.push_back(r1);
    board.push_back(r2);
    board.push_back(r3);
    board.push_back(r4);
    board.push_back(r5);
    board.push_back(r6);
    board.push_back(r7);
    board.push_back(r8);
    board.push_back(r9);
    board.push_back(r10);
    /*
     ["aaa","abb","abb","bbb","bbb","aaa","bbb","abb","aab","aba"]
     "aabaaaabbb"
     */
    
    if(obj.exist(board,"aabaaaabbb"))
        cout<<"found";
    else
        cout<<"not found";
    return 0;
}
