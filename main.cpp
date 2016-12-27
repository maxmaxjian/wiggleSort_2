#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

class solution {
  public:
    // // O(n^2) solution
    // void wiggleSort(std::vector<int> & nums) {
    //     size_t curr = 0;
    //     while (curr < nums.size()) {
    //         if (curr%2 == 0) {
    //             auto it = std::min_element(nums.begin()+curr, nums.end());
    //             std::swap(nums[curr], *it);
    //         }
    //         else  {
    //             auto it = std::max_element(nums.begin()+curr, nums.end());
    //             std::swap(nums[curr], *it);
    //         }
    //         curr++;
    //     }
    // }

    // O(n) solution
    void wiggleSort(std::vector<int> & nums) {        
    //     size_t mid = nums.size()/2;
    //     std::nth_element(nums.begin(), nums.begin()+mid, nums.end());
    //     std::cout << std::endl;
    //     std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout," "));
    //     std::cout << std::endl;

    //     size_t first, second;
    //     if (nums.size()%2 == 0) {
    //         first = 1, second = mid;
    //         while (second < nums.size()) {
    //             std::swap(nums[first], nums[second]);
    //             std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout," "));
    //             std::cout << std::endl;
    //             first += 2;
    //             second++;
    //         }
    //     }
    //     else {
    //         first = 1, second = mid+1;
    //         while (second < nums.size()) {
    //             std::swap(nums[first], nums[second]);
    //             std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout," "));
    //             std::cout << std::endl;
    //             first += 2;
    //             second++;
    //         }
    //     }

        size_t mid = nums.size()%2==0 ? nums.size()/2 : nums.size()/2+1;
        std::nth_element(nums.begin(), nums.begin()+mid, nums.end());
        std::cout << std::endl;
        std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout," "));
        std::cout << std::endl;

        size_t first = 1, second = mid;
        while (second < nums.size()) {
            size_t i = second+1;
            while (i < nums.size() && nums[second] == nums[first-1])
                std::swap(nums[second], nums[i++]);
            std::swap(nums[first], nums[second]);
            std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout," "));
            std::cout << std::endl;
            first += 2;
            second++;
        }
    }
};

int main() {
    // std::vector<int> nums{1,5,1,1,6,2};
    std::vector<int> nums{1,3,2,2,3,1};
    
    std::cout << "Before wiggle sorting:\n";
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;

    solution soln;
    soln.wiggleSort(nums);
    std::cout << "After wiggle sorting:\n";
    std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout," "));
    std::cout << std::endl;
}
