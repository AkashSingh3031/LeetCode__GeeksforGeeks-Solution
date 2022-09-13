class Solution {
public:
    using VarsT = unordered_map<string, stack<int>>;

    bool isNumber(char c) {
        return (c >= '0' && c <= '9') || c == '-';
    }

    vector<string> parseSubExprs(const string& expr) {
        int openCnt = 0;
        size_t start = 0;
        vector<string> subExprs;
        for (size_t i = 1; i < expr.size(); ++i) {
            if (expr[i] == ' ' && openCnt == 0) {
                subExprs.push_back(expr.substr(start, i - start));
                start = i + 1;
            } else if (expr[i] == '(') {
                ++openCnt;
            } else if (expr[i] == ')') {
                --openCnt;
            }
        }
        subExprs.push_back(expr.substr(start));
        return subExprs;
    }

    int evalImpl(const string& expr, VarsT& vars) {
        if (isNumber(expr[0]))
            return stoi(expr);
        if (expr[0] == '(')
            return evalImpl(expr.substr(1, expr.size() - 2), vars);
        auto subExprs = parseSubExprs(expr);
        if (subExprs.front() == "add") {
            return evalImpl(subExprs[1], vars) + evalImpl(subExprs[2], vars);
        } else if (subExprs.front() == "mult") {
            return evalImpl(subExprs[1], vars) * evalImpl(subExprs[2], vars);
        } else if (subExprs.front() == "let") {
            vector<string> pushedVars;
            for (size_t i = 1; i < subExprs.size() - 1; i += 2) {
                pushedVars.push_back(subExprs[i]);
                vars[subExprs[i]].push(evalImpl(subExprs[i + 1], vars));
            }
            auto res = evalImpl(subExprs.back(), vars);
            for (const auto& var : pushedVars)
                vars[var].pop();
            return res;
        }
        return vars[expr].top();
    }

    int evaluate(const string& exp) {
        VarsT vars;
        return evalImpl(exp, vars);
    }
};