type state struct {
    frnt int
    back int
}
var memo map[state]float64 = make(map[state]float64)

func soupServings(n int) float64 {
    if (n > 4800) { return 1.0 }
    ans := dfs(n, n)
    return ans
}

func dfs(aLeft, bLeft int) float64 {
    op := [4][2]int{{-100, 0}, {-75, -25}, {-50, -50}, {-25, -75}}
    storage := make([]float64, 4)

    tmpKey := state{aLeft, bLeft}
    if val, ok := memo[tmpKey]; ok {
        return val
    }

    for i, v := range op {
        frnt := aLeft + v[0]
        back := bLeft + op[i][1]
        switch {
        case frnt <= 0 && back <= 0:
            storage[i] = 0.5
        case frnt <= 0:
            storage[i] = 1
        case back <= 0:
            storage[i] = 0
        default:
            storage[i] = dfs(frnt, back)
        }
    }
    memo[tmpKey] = 0.25 * (storage[0] + storage[1] + storage[2] + storage[3])
    return memo[tmpKey]
}