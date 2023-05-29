#include <iostream>
#define DATA_LEN 100000
using namespace std;

typedef int Data;
typedef int (*PriorityComp)(Data, Data);

struct Heap{
	PriorityComp comp;
	int count;
	Data heapArr[DATA_LEN+2];
};

// if ) d1 > d2 : return high than 0, d1 < d2 : return low than 0, d1 == d2 : return 0
int CompInt(int d1, int d2){
	//return d1 - d2;
	return d2 - d1;
}

void HeapInit(Heap* ph, PriorityComp pc){
	ph->count=0;
	ph->comp = pc;
}
int HIsEmepty(Heap* ph){
	if(ph->count == 0)
		return 1;
	else
		return 0;
}
int GetParentIdx(int idx){
	return idx/2;
}
int GetLChildIdx(int idx){
	return idx*2;
}
int GetRChildIdx(int idx){
	return GetLChildIdx(idx)+1;
}
int GetHighPriChildIdx(Heap* ph, int idx){
	if(GetLChildIdx(idx)>ph->count)
		return 0;
	else if(GetLChildIdx(idx) == ph->count)
		return GetLChildIdx(idx);
	else{
		if(ph->comp(ph->heapArr[GetLChildIdx(idx)], ph->heapArr[GetRChildIdx(idx)]) < 0)
			return GetRChildIdx(idx);
		else
			return GetLChildIdx(idx);
	}
}
void HInsert(Heap* ph, Data data){
	int idx = ph->count+1;
	
	while(idx != 1){
		if(ph->comp(data, ph->heapArr[GetParentIdx(idx)]) > 0){
			ph->heapArr[idx] = ph->heapArr[GetParentIdx(idx)];
			idx = GetParentIdx(idx);
		}
		else break;
	}
	
	ph->heapArr[idx] = data;
	ph->count += 1;
}
Data HDelete(Heap* ph){
	if(HIsEmepty(ph))
		return 0;
	
	Data removeData = ph->heapArr[1];
	Data lastNode = ph->heapArr[ph->count];
	
	int parentIdx = 1;
	int childIdx;
	
	while(childIdx = GetHighPriChildIdx(ph, parentIdx)){
		if(ph->comp(lastNode, ph->heapArr[childIdx]) >= 0)
			break;
		ph->heapArr[parentIdx] = ph->heapArr[childIdx];
		parentIdx = childIdx;
	}
	
	ph->heapArr[parentIdx] = lastNode;
	ph->count -= 1;
	return removeData;
}


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	Heap heap;
	HeapInit(&heap, CompInt);
	
	int n, cards;
	cin >> n;
	
		
	for(int i=1; i<=n; i++){
		cin >> cards;
		HInsert(&heap, cards);
	}
	
	
	if(n==1){
		cout << 0 << "\n";
		return 0;
	}
	
	int sum = HDelete(&heap) + HDelete(&heap);
	int total_sum = sum;
	while(!HIsEmepty(&heap)){
		HInsert(&heap, sum);
		total_sum += sum = HDelete(&heap) + HDelete(&heap);
	}
	cout << total_sum << "\n";
	
}