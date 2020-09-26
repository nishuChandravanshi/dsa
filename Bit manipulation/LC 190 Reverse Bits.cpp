class Solution {
public:
    uint32_t reverseByte(uint32_t byte, map<uint32_t, uint32_t>& map)
    {
        if(map.find(byte) != map.end())
            return map[byte];
        
        uint32_t val = (byte * 0x0202020202 & 0x010884422010) % 1023;
        
        map[byte] = val;
        
        return val;
    }
    
    uint32_t reverseBits(uint32_t n) {
        
        uint32_t ans = 0, pos = 24;
        map<uint32_t, uint32_t> map;
        
        while(n != 0){
            
            ans += reverseByte((n & 0xff), map) << pos;
            n = n >> 8;
            pos -= 8;
            
        }
        
        return ans;
    }
};

/* T : O(1), S : O(1)
-reversed bytes(0xff => 8 bits) first and then shifted to the desired pos
-so as to optimize it in comparison to doing with bits, 
-map used so as if same byte appears then simply return the reversed value to that byte instead of reversing it again
-reversing byte directly by -> (byte * 0x0202020202 & 0x010884422010) % 1023 ---> some method of bits manipulation
*/
