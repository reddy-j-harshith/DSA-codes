#include<bits/stdc++.h>
using namespace std;

// bool comp(int a, int b){
//     if(a % 2 && b % 2) return true;
//     else           return false;
// }

bool comp1(pair<int, int> &a, pair<int, int> &b){
    if(a.second < b.second) return true;
    if(a.second > b.second) return false;

    if(a.first > b.first) return true;

    return false;
}

int main(){
    // vector<int> v;
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(2);
    // v.push_back(9);
    // v.emplace_back(12);



    // vector<int> copy(5, 69);    
    
    // for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
    //     cout<<*(it)<<" ";

    // v.swap(copy);
    // cout<<endl;

    // v.pop_back();
    // for(auto it = v.begin(); it != v.end(); it++)
    //     cout<<" "<<*(it);





    // list<int> ls;
    // ls.push_back(3);
    // ls.emplace_back(1);
    // ls.emplace_front(8);
    // ls.push_front(0);

    // ls.pop_front();

    // for(list<int>::iterator it = ls.begin(); it != ls.end(); it++)
    //     cout<<*(it)<<" ";

    // auto it = ls.begin();

    
 
    // advance(it, 2);
    // cout<<" "<<*(it);
    // advance(it, 2);
    // cout<<" "<<*(it);
    // return 0;







    // // stack<int> st;

    // st.push(1);
    // st.push(4);
    // st.push(5);
    // st.emplace(6);

    // stack<int> tempStack = st;
    // while(!tempStack.empty()){
    //     cout<<tempStack.top()<<" ";
    //     tempStack.pop();
    // }







    // queue<int> q;
    // q.push(1);
    // q.push(4);
    // q.push(8);
    // q.push(10);

    // queue<int> tempQueue = q;

    // while(!tempQueue.empty()){
    //     cout<<tempQueue.front()<<" ";
    //     tempQueue.pop();
    // }







    // priority_queue<int, vector<int>, decltype(&comp)> pq(&comp);

    // pq.push(5);
    // pq.push(2);
    // pq.push(8);
    // pq.emplace(10);

    // cout<<pq.top()<<endl;


    // auto tempPQ = pq;

    // while(tempPQ.size() != 0){
    //     cout<<tempPQ.top()<<" ";
    //     tempPQ.pop();
    // }

    // cout<<endl<<pq.top()<<endl;




    // deque<int> dq;

    // dq.push_back(3);
    // dq.emplace_back(1);
    // dq.push_front(5);
    // dq.emplace_front(2);
    // for(auto it = dq.begin(); it != dq.end(); it++)
    //     cout<<*(it)<<" ";

    // dq.pop_back();

    //     for(auto it = dq.begin(); it != dq.end(); it++)
    //     cout<<*(it)<<" ";

    // dq.pop_back();

    //     for(auto it = dq.begin(); it != dq.end(); it++)
    //     cout<<*(it)<<" ";





    // set<string> st;
    // st.insert("Hello");
    // st.insert("Hi");
    // st.insert("Harry");
    // st.insert("Hari");
    // st.emplace("Hanuman");
    // st.emplace("Harry Potter");

    // auto itr1 = st.find("Hanuman");
    // auto itr2 = st.find("Harry Hello");
    // st.erase(itr1, itr2);

    // for(auto it = st.begin(); it != st.end(); it++)
    //     cout<<*(it)<<endl;








    // multiset<int> ms;
    // ms.insert(1);
    // ms.insert(2);
    // ms.insert(3);
    // ms.insert(1);
    // ms.insert(1);

    // ms.erase(ms.find(1));

    // for(auto itr = ms.begin(); itr != ms.end(); itr++)
    //     cout<<*(itr)<<" ";









    // unordered_set<int> uset;

    // uset.insert(1);
    // uset.insert(4);
    // uset.insert(1);
    // uset.insert(8);
    // uset.insert(11);

    // uset.erase(11);

    // for(auto itr = uset.begin(); itr != uset.end(); itr++)
    //     cout<<*(itr)<<" ";








    map<pair<int, int>, int> mpp;
    mpp.insert({{1, 3}, 4});
    mpp.insert({{4, 4}, 6});
    mpp.insert({{7, 3}, 5});
    mpp.insert({{2, 9}, 2});
    mpp.insert({{6, 0}, 6});
    mpp.insert({{1, 5}, 4});
    mpp.emplace(make_pair(1, 4), 5);
    for(auto element : mpp)
        cout<<"Point: x = "<<element.first.first<<", y = "<<element.first.second<<"\. And the value is "<<element.second<<"."<<endl; 

    cout<<__builtin_popcount(7)<<endl;
    string s = "cba";
    // sort(s.begin(), s.end());
    do{
        cout<<s<<endl;
    }while(next_permutation(s.begin(), s.end()));

    cout<<*max_element(s.begin(), s.end())<<endl;
    cout<<*min_element(s.begin(), s.end())<<endl;
    cout<<(int)binary_search(s.begin(), s.end(), 'b')<<endl;
    
    pair<int, int> array[] = {{2, 1}, {9, 3}, {4, 1}};
    sort(array, array + 3, comp1);
    for(auto element : array)
        cout<<element.first<<" "<<element.second<<endl;
    
    
    // int a[] = {8, 4, 7, 4, 3, 7};
    // sort(a, a + 6);

    // vector<int> vec = {2,  5, 6, 3, 7, 8};
    // sort(vec.begin(), vec.end(), greater<int>());

    // for(auto element : a)
    //     cout<<element<<" ";
    // cout<<endl;

    // for(auto element : vec)
    //     cout<<element<<" ";

}

