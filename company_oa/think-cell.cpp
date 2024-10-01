#include <map>
#include <bits/stdc++.h>
#include <utility>
using namespace std;

template<typename K, typename V>
class interval_map {
	friend void IntervalMapTest();
	V m_valBegin;
	std::map<K,V> m_map;
public:
	// constructor associates whole range of K with val
	template<typename V_forward>
	interval_map(V_forward&& val)
	: m_valBegin(std::forward<V_forward>(val))
	{}

	// Assign value val to interval [keyBegin, keyEnd).
	// Overwrite previous values in this interval.
	// Conforming to the C++ Standard Library conventions, the interval
	// includes keyBegin, but excludes keyEnd.
	// If !( keyBegin < keyEnd ), this designates an empty interval,
	// and assign must do nothing.

	// my code
	template<typename V_forward>
	void assign( K const& keyBegin, K const& keyEnd, V_forward&& val )
		requires (std::is_same<std::remove_cvref_t<V_forward>, V>::value)
	{
		// code begins
		if( !(keyBegin < keyEnd) ) return;

		//find the smallest key greater than or equal to keyBegin
		auto begin_it = m_map.lower_bound(keyBegin);

		//if there are no keys inserted yet, assign (m_map[keyBegin]=val) and (m_map[keyEnd]=m_valBegin)
		if(m_map.size()==0)
		{
			if(!(val==m_valBegin))
			{
				m_map[keyBegin] = std::forward<V_forward>(val);
				m_map[keyEnd] =  m_valBegin;
			}
			return;
		}

		// key_before_begin_it is the iterator to the key before keyBegin
		auto key_before_begin_it = begin_it;

		// check is true if begin_it is the first key in the map, else check is false
		bool check = true;
		if(!(begin_it==m_map.begin()))
		{
			check = false;
			key_before_begin_it--;
		}

		// find the smallest key greater than or equal to keyEnd
		auto end_key_it = m_map.lower_bound(keyEnd);

		// if begin_it is equal to end_key_it, this means that no key exists in interval - [beginKey,endKey).
		if(begin_it==end_key_it)
		{
			if(check) 
			{
				if(!(m_valBegin==val))
				{
					m_map[keyBegin] = std::forward<V_forward>(val);
					// next interval that exists start after the endKey so the previous interval will continue from keyEnd
					if( (end_key_it->first)<keyEnd || keyEnd<(end_key_it->first) )
					{
						m_map[keyEnd] = m_valBegin;
					}
					// next interval starts from keyEnd and its value == val so we merge it with the current interval
					else if((end_key_it->second) == val)
					{
						m_map.erase(end_key_it);
					}
				}
				return;
			}
			else
			{
				if(!(key_before_begin_it->second == val))
				{
					m_map[keyBegin] = std::forward<V_forward>(val);

					// there is no interval after the current one, so after the current interval we will put the same value as that of the previous interval.
					if(end_key_it == m_map.end()) 
					{
						m_map[keyEnd] = key_before_begin_it->second;
					}
					// next interval that exists start after the keyEnd so the previous interval will continue from keyEnd
					else if( (end_key_it->first)<keyEnd || keyEnd<(end_key_it->first) )
					{
						m_map[keyEnd] = key_before_begin_it->second;
					}
					// next interval starts from keyEnd and its value == val so we merge it with the current interval
					else if((end_key_it->second)==val)
					{
						m_map.erase(end_key_it);
					}
				}
				return;
			}
		}
		// Now, we know that there exists atleast 1 interval which starts between keyBegin and keyEnd

		// previous_to_end_key_it is the last element that starts in the interval [beginKey,endKey)
		auto previous_to_end_key_it = end_key_it;
		previous_to_end_key_it--;

		// if value of previous_to_end_key_it is not equal to val, so we make an interval for the same that starts at keyEnd
		if(!(previous_to_end_key_it->second == val))
		{ 
			if( end_key_it == m_map.end() || ((end_key_it->first)<keyEnd || keyEnd<(end_key_it->first)) )
			{
				m_map[keyEnd] = previous_to_end_key_it->second;
				end_key_it--;
			}
		}

		// erase all the keys between begin_it to end_key_it because they no longer are needed, and the case for the last key in this interval is handled above.
		while(!(begin_it==end_key_it)){
			begin_it = m_map.erase(begin_it);
		}

		// Now, if val is same as the value of the interval before it, so remove the current interval too.
		if((begin_it->second)==val){
			begin_it = m_map.erase(begin_it);
		}

		// finally assigning keyBegin's value as val if it is already not same to the previous interval.
		if(check){
			if(!(m_valBegin==val)){
                m_map.emplace(keyBegin, std::forward<V_forward>(val));
			}
		}
		else{
			if(!(key_before_begin_it->second == val)){
                m_map.emplace(keyBegin, std::forward<V_forward>(val));
			}
		}
		return;
	}

	// look-up of the value associated with key
	V const& operator[]( K const& key ) const {
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) {
			return m_valBegin;
		} else {
			return (--it)->second;
		}
	}
};




// Many solutions we receive are incorrect. Consider using a randomized test
// to discover the cases that your implementation does not handle correctly.
// We recommend to implement a test function that tests the functionality of
// the interval_map, for example using a map of int intervals to char.


std::random_device rd;
std::mt19937 gen(rd());

int getRandomInteger(int start, int end) {
    if (start > end) {
        std::swap(start, end);
    }
    std::uniform_int_distribution<> dis(start, end);
    return dis(gen);
}

char getRandomCharacter() {
    const char lower_bound = 'A';
    const char upper_bound = 'D';
    std::uniform_int_distribution<> dis(lower_bound, upper_bound);
    return static_cast<char>(dis(gen));
}


void IntervalMapTest(){
	int start = -10;
	int end = 10;
	unordered_map<int,char> v;
	char c = getRandomCharacter();
	for(int i=start-1;i<=end;i++){
		v[i] = c;
	}
	interval_map<int,char> mp(c);

	int iterations = 1000000;
	int checkafter = 1;
	vector<pair<pair<int,int>,char>> tot;
	vector<pair<int,char>> prev1;
	vector<pair<int,char>> prev2;
	for(int j=0;j<iterations;j++){
		int keybegin = getRandomInteger(start,end);
		int keyend = getRandomInteger(keybegin+1,end);
		if(keyend<start || keyend>end || keybegin<start || keybegin>end)continue;
		char ch = getRandomCharacter();

		tot.push_back({{keybegin,keyend},ch});
		mp.assign(keybegin,keyend,ch);

		for(int r=keybegin;r<keyend;r++){
			v[r] = ch;
		}
		// if(j==iterations-1){
		if(1){
			vector<pair<int,char>> v1;
			vector<pair<int,char>> v2;
			v1.push_back({start-1,v[start-1]});
			for(int k=start;k<=end;k++){
				if(v[k]!=v[k-1]){
					v1.push_back({k,v[k]});
				}
			}
			v2.push_back({start-1,mp.m_valBegin});
			for(auto e:(mp.m_map)){
				v2.push_back({e.first,e.second});
			}

			// cout<<(v1==v2)<<endl;
			if(v1!=v2){
				cout<<"here"<<endl;
				for(auto i:tot){
					cout<<i.first.first<<" "<<i.first.second<<" "<<i.second<<endl;
				}
				cout<<"prevvvvvvvvvvvvvvvvvvvvvvvvvvv"<<endl;
				for(auto i:prev1){
					cout<<i.first<<" "<<i.second<<endl;
				}
				cout<<"wwwwwwwwwwwwwwwwwwwwwwwwwwwwwwww"<<endl;
				// for(auto i:prev2){
				// 	cout<<i.first<<" "<<i.second<<endl;
				// }
				cout<<"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa"<<endl;
				for(auto i:v1){
					cout<<i.first<<" "<<i.second<<endl;
				}
				cout<<"xxxxxxxxxxxxxxxxxxxxxxxxxxxx"<<endl;
				for(auto i:v2){
					cout<<i.first<<" "<<i.second<<endl;
				}
				cout<<"gggggggggggggggggggggggggggggggggggg"<<endl;
				break;
			}
			// prev1 = v1;
			// prev2 = v2;
		}
	}
	cout<<"done"<<endl;
	// mp.assign(100,200,'a');
	// mp.assign(0,300,'b');
	// vector<pair<int,char>> v2;
	// v2.push_back({start-1,mp.m_valBegin});
	// for(auto e:(mp.m_map)){
	// 	v2.push_back({e.first,e.second});
	// }
	// for(auto g:v2){
	// 	cout<<g.first<<" "<<g.second<<endl;
	// }
}

int main(){
	IntervalMapTest();
}