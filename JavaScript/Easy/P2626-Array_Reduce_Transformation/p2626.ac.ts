type Fn = (accum: number, curr: number) => number

function reduce(nums: number[], fn: Fn, init: number): number {
    nums.forEach(e => init = fn(init, e))
    return init
};