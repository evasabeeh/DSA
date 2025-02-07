sizeof(char) // 1 byte

sizeof(void) // The size of void pointer varies system to system. If the system is 16-bit, size of void pointer is 2 bytes. If the system is 32-bit, size of void pointer is 4 bytes. If the system is 64-bit, size of void pointer is 8 bytes.

sizeof(arr) / sizeof(arr[0]) // array size

int a[5] = {4};           // {4, 0, 0, 0, 0}
sort(arr, arr+2)              //sort array within range
sort(arr, arr+2, greater<int>())             //descending
sort(a, a+3, comp)            //sort in desired order

M_PI             // pi=3.14 (use const only)


//set: sorted and unique
unordered_set<int> s;
s.insert(3);
s.begin();    //iterator to first element
s.end();      //iterator after last element
s.count(9);   //returns 1 or 0
s.clear();
s.find(3)!=s.end();   //returns true
s.erase();    //delete element or elements in a range
s.empty();
s.size();
for(auto it=s.first; it!=s.end(); it++)
cout<<*it;        //print element


//multiset case store duplicate elements: sorted and not-unique
minn = *v.begin(), maxx = *v.rbegin();      
v.erase(v.find(x))          // to find x and delete x
v.insert(x)


//vector
vector<int> v;
//rbegin - reverse begin

v.pop_back();         //remove last element
v.push_back(4);       //or v.emplace_back(3);
v.insert(v.begin()+1, 5)
auto it=v.begin();
v.insert(4, it);         //insert element at specified position
v.erase(it, it+2);
v.clear();
v.back();       //last
v.empty();
vector<int> vec(n, 2);   //vector of size n with all default values of 2  {2, 2, 2,...}

vector<int>::iterator itr=v.begin();            //iterator for vector
cout<<(*itr);

vector<vector<int>> vec(n, vector<int>(m, 9));      //m cols and n rows
*max_element(v.begin(), v.end());
sort(v.rbegin(), v.rend());     //descending
accumulate(candy.begin(), candy.end(), 0);    //sum
upper_bound(v.begin(), v.end(), x);           //iterator to first greater element than target found in vector
lower_bound(v.begin(), v.end(), x);           //iterator to target or first greater element than target

auto it=find(vec.begin(), vec.end(), x);
if (it != vec.end())
return true;

//pair
pair<int, int> p;
int a=p.first, b=p.second;     //extract first and second element from the pair
pair<int, int> arr[]={{1, 2}}  //pair array
cout<<arr[0].first;
make_pair(2, 3);

next_permutation(vec.begin(), vec.end());      //next permutation of digits


//map
map<int, int> mp;
for(auto it=mp.begin(); it!=mp.end();it++)
cout<<it->first;
for(auto it: mp)
cout<<mp.first;


//list - inserting and erasing of elements in constant time and iterating in both directions
//list allows front operation also
li.reverse();
li.sort();
li.push_front();


priority_queue<int, vector<int>, greater<int>> pq;       // min heap
priority_queue<int> pq;           // max heap
pq.top();   // pq.front() in pq

__builtin_popcount(n)            // count set bits in an number or popcountll()


auto a = 8;     //auto assigns datatype to var acc to data



// binary search
binary_search(v.begin(), v.end(), x)


//count of digits
int a = 78342;
int count = (int)(log10(n)+1);
int arr[256];      //if there are all characters to be hashed, uppercase, lowercase, digits, special chars all


//sort vector based on second element
sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b){
  return a[1]<b[1];
});

//sort string numbers according to numeric values
sort(nums.begin(), nums.end(), [](const auto &a, const auto &b){
  if(a.size()==b.size())
  return a<b;
            
  return a.size()<b.size();
});


// comapre function : sort id vector based on position vector
auto compare = [&](int id1, int id2){
  return positions[id1] <= positions[id2];
};
sort(id.begin(), id.end(), compare);


//if vector is a subset of another vector
bool f = includes(b.begin(), b.end(), a.begin(), a.end());    //if A is a subset of B


//reverse number
(digit * 10^i) + ans;

//number
ans * 10 + digit

// max, min for multiple values
max({x, y, z, ...})

// iota to assign successive values
iota(vec.begin(), vec.end(), 4);         // =>   4, 5, 6, 7, 8... size of vector

// check power of some number in terms of 2
log2(n)

// initialise array with value -1
memset(arr, -1, sizeof(arr));

//Can have only 1 destructor per class = > destructor can not be overloaded as it is only one way to destroy the object created by the constructor

//sum of sq num = [n(n + 1)(2n + 1)] / 6

toupper(c)

// compare function should be static
static bool compare(int a, int b){}
