// class Solution {
// public:
//     string decodeAtIndex(string s, int k) {
//         stack<string> st;
//         int n=s.size();
//         for(int i=0;i<n;i++){
//             if('2'<=s[i] && s[i]<='9'){
//                 string temp=st.top();
//                 st.pop();
//                 int times=s[i]-'0';
//                 while(--times){
//                     temp+=temp;
//                 }
//                 st.push(temp);
//             }else{
//                 if(st.empty()){
//                     string temp;
//                     temp+=s[i];
//                     st.push(temp);
//                 }else{
//                     string temp=st.top();
//                     st.pop();
//                     temp+=s[i];
//                     st.push(temp);
//                 }
//             }
//         }
//         string ans=st.top();
//         cout<<ans<<endl;
//         return to_string(ans[k-1]);
//     }
// };
class Solution {
public:
    string decodeAtIndex(string encodedString, int k) {
        stack<long long> characterLengths; // Stores the lengths of characters in the decoded string

        // Calculate lengths for each character in the encoded string
        characterLengths.push(0); // Start with 0 length

        for (size_t i = 0; i < encodedString.length(); ++i) {
            if (isdigit(encodedString[i])) {
                // If the character is a digit, update the length based on the digit
                long long length = characterLengths.top() * (encodedString[i] - '0');
                characterLengths.push(length);
            } else {
                // If the character is a letter, increment the length
                long long length = characterLengths.top() + 1;
                characterLengths.push(length);
            }
        }

        // Traverse the character lengths to decode and find the kth character
        size_t ln = characterLengths.size();
        while (!characterLengths.empty()) {
            k %= characterLengths.top(); // Adjust k based on the character length
            ln--;
            // If k is 0 and the character is an alphabet letter, return it
            if (k == 0 && isalpha(encodedString[ln - 1])) {
                return string(1, encodedString[ln - 1]);
            }

            // Move to the previous character length
            characterLengths.pop();
        }

        return ""; // Return an empty string if no character is found
    }
};