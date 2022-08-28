#include<unordered_map>

vector <int> longestConsecutiveIncreasingSequence(int *arr,int n){
    unordered_map<int,bool> visitedElements;
    unordered_map<int,int>elementToIndexMapping;
    
    for(int i=0;i<n;i++){
        elementToIndexMapping[arr[i]]=i;
        if(visitedElements.count(arr[i])==0){
            visitedElements[arr[i]]= true;
        }
    }
    
    vector<int> longestSequence;
    int globalMaxSequenceLength = 1;
    int globalMinStartIndex = 0;
    for(int i=0;i<n;i++){
        int num = arr[i];
        int currentMinStartIndex = i;
        int count = 0;
        int tempNum = num;
        
        while(visitedElements.count(tempNum)==1 && visitedElements[tempNum]==true){
            visitedElements[tempNum] = false;
            count++;
            tempNum++;
        }
        
        tempNum = num - 1;
        while( visitedElements.count(tempNum)==1 && visitedElements[tempNum]==true){
            visitedElements[tempNum] = false;
            count++;
            currentMinStartIndex = elementToIndexMapping[tempNum];
            tempNum--;
        }
        if(count > globalMaxSequenceLength){
            globalMaxSequenceLength = count;
            globalMinStartIndex = currentMinStartIndex;
        } else if(count == globalMaxSequenceLength){
            if(currentMinStartIndex < globalMinStartIndex){
                globalMinStartIndex = currentMinStartIndex;
            }
        }
    }
    int globalStartNum = arr[globalMinStartIndex];
    
    longestSequence.push_back(globalStartNum);
    if(globalMaxSequenceLength > 1 ){
        longestSequence.push_back(globalStartNum + globalMaxSequenceLength-1);
    }
    return longestSequence;
}
