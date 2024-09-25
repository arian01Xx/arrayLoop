#include <iostream>
#include <vector>

using namespace std;

class SolutionFourtyOne{
public:
    int next(vector<int>& nums, int i){
        int n=nums.size();
        //calcula el siguiente indice de forma circular
        return ((i+nums[i]%n)+n)%n;
    }
    bool circularArrayLoop(vector<int>& nums) {
        int n=nums.size();
        for(int i=0; i<n; i++){
            int slow=i;
            int fast=next(nums,i);
            while(nums[slow]*nums[fast]>0 && nums[slow]*nums[next(nums,fast)]>0){
                if(slow==fast){
                    if(slow!=next(nums,slow)) return true;
                    break;
                }
                slow=next(nums,slow);
                fast=next(nums,next(nums,fast));
            }
        }
        return false;
    }
};

int main(){
    return 0;
}