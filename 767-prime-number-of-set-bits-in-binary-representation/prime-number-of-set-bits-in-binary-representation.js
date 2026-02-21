/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var countPrimeSetBits = function(left, right) {
    let ans = 0
    for(let n = left;n<=right;n++){
        let c = 0
        let a = n
        while(a>0){
            c += a&1
            a = a>>1
        }
        let p = true
        for(let i=2;i<=c/2;i++){
            if(c%i===0){
                p = false
                break
            }
        }
        // console.log(n,c,p)
        if(p&& c!==1)ans++
    }
    return ans
};