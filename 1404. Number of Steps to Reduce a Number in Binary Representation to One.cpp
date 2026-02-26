// class Solution {
// public:
//     int numSteps(string s) {
//         int decimal = stoi(s, nullptr, 2);
//         int count = 0 ;
//         while(decimal >= 1){
//             if(decimal % 2 != 0){
//                 decimal += 1;
//             }
//             count++;
//             decimal /= 2;
//         }
//         return count;
//     }
// };

class Solution {
public:
    int numSteps(string s) {
        int steps = 0;
        int carry = 0;
        for (int i = s.length() - 1; i > 0; i--) {
            
            if ((s[i] - '0' + carry) % 2 == 1) {
                // odd → add 1 (creates carry)
                steps += 2; 
                carry = 1;
            } else {
                // even → divide by 2
                steps += 1;
            }
        }

        return steps + carry;
    }
};
