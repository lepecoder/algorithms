/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution {
  public:
    TreeNode *convertBiNode(TreeNode *root) {
        stack<TreeNode *> stk;
        TreeNode *dummy = new TreeNode(0);
        TreeNode *d = dummy;
        TreeNode *p = root;
        while (!stk.empty() || p) {
            while (p) {
                stk.emplace(p);
                p = p->left;
            }
            if (!stk.empty()) {
                p = stk.top();
                cout << p->val << ' ';
                stk.pop();
                d->left = nullptr;
                d->right = p;
                d = p;
                p = p->right;
            }
        }
        cout << 1;
        return dummy;
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) { return !isspace(ch); }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) { return !isspace(ch); }).base(), input.end());
}

TreeNode *stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) { return nullptr; }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode *root = new TreeNode(stoi(item));
    queue<TreeNode *> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode *node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) { break; }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) { break; }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

string treeNodeToString(TreeNode *root) {
    if (root == nullptr) { return "[]"; }

    string output = "";
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode *node = q.front();
        q.pop();

        if (node == nullptr) {
            output += "null, ";
            continue;
        }

        output += to_string(node->val) + ", ";
        q.push(node->left);
        q.push(node->right);
    }
    return "[" + output.substr(0, output.length() - 2) + "]";
}

int main() {
    string line;
    while (getline(cin, line)) {
        line =
            "[96187,-404,260448753,-2537,-2,894270,475276312,-632410,-632,-373,4,616278,3665981,426061938,639949139,-4647449,-385914,-748,-493,-383,-6,-1,17,"
            "246214,651750,2533055,95565548,323025120,447557173,497556341,1304784915,-773280795,-905459,-501759,-27163,-884,-663,-569,-432,null,null,-38,-3,-1,"
            "0,8,2442,142066,382139,616554,733089,923288,3009029,23805558,110413551,null,423543065,null,450046964,null,638005707,696449656,1540990922,-"
            "1737879974,-5591506,-1975805,-728104,-616027,-419605,-84301,-22328,-924,-768,-707,null,-624,-508,null,null,-66,-26,-6,-2,-1,-1,0,2,6,8,55,3992,"
            "132684,161143,292882,452441,null,647710,711033,885444,922523,2002798,null,3306107,8750867,80678025,null,230850461,null,null,null,null,622993674,"
            "null,686638423,1106819064,1379631882,2087143142,-2129284901,-831558438,-55025311,-5494911,-2499523,-1189464,-744345,-673493,null,-522130,-455114,"
            "null,-99385,-32323,-25392,-9425,-952,null,null,null,null,null,null,null,null,-504,-75,-48,-29,-8,-6,-5,-3,null,-2,-1,null,null,null,0,1,3,6,7,8,"
            "13,37,411,3643,5879,null,null,null,181133,null,374804,410426,603697,620442,null,700949,null,870935,886732,null,null,1980291,2504670,null,null,"
            "4525705,9603353,54297435,81753670,null,238432443,563952925,null,644969179,null,841541691,1179273039,1369546849,1397387221,1681419026,2140219715,"
            "null,-2067674660,-1318214282,-827205519,-390880210,-46501532,-5532569,-4831355,-2696899,null,-1201065,-921126,-843231,null,-690699,-633348,-"
            "576331,-508146,-458000,-454585,-224845,-86245,-48502,-30409,null,null,-11043,-7523,-1135,null,null,null,-92,-75,-52,-42,-38,-26,-8,-7,null,null,-"
            "6,-3,null,null,null,-2,null,null,null,0,0,null,null,null,5,6,7,null,null,null,9,13,29,52,302,899,3185,3838,5760,30941,172548,186465,null,null,"
            "null,null,562443,null,null,null,null,null,794580,null,null,null,1753392,null,null,null,3748309,4821923,8816832,14330450,36874325,78617139,null,"
            "95141719,null,242940729,null,null,null,null,758828478,970103380,1107599732,1301349579,null,null,null,1432073847,1545209687,2033266955,2092055814,"
            "null,-2076093712,-2039935815,-1627685338,-962262584,null,-783439090,-467105450,-330451771,-47528924,-38776322,-5563063,null,null,null,-4436338,"
            "null,-1608170,null,null,-914741,-891413,-795127,null,null,null,null,null,-542912,null,-502928,null,null,null,-431235,-377435,-170253,null,null,-"
            "50136,-38756,null,null,-12462,null,-9110,-7454,-2184,-991,-94,-81,null,null,-62,-49,-43,-39,null,-35,null,null,-9,null,-7,-6,-6,-5,-4,null,null,"
            "null,null,null,null,1,5,5,null,null,null,null,null,null,null,null,null,34,44,null,266,362,578,2294,2540,3394,null,3973,5239,null,7744,71493,null,"
            "null,null,null,552739,null,751820,null,null,null,null,4285607,null,6717341,null,null,9721381,16037048,24418149,42906621,null,78654907,null,null,"
            "null,null,699841775,null,863855439,1018896239,null,1109247681,1243760815,null,null,null,null,1596519965,1907521894,2075992829,null,2137198544,"
            "null,null,-2053163410,-1933881945,-1668407418,-1616638979,-1192411350,-852210697,-792614839,null,-579113693,-423756294,-332854849,-302749804,-"
            "51043385,-47322269,-41875925,-8586550,null,null,null,-2948791,null,null,null,null,null,-862111,null,-776391,null,null,null,null,null,null,-382144,"
            "-251723,-199196,null,-79102,null,-43424,-36530,-20126,null,-9261,-9036,null,-6129,-2428,-1528,null,null,-99,-92,-91,null,-66,-61,null,null,null,-"
            "42,null,null,-38,null,null,null,-8,null,null,null,null,null,-5,-5,null,null,null,1,4,null,null,null,null,null,37,48,257,null,346,399,484,798,1885,"
            "null,null,2591,null,null,null,null,4450,5412,6005,27036,59641,90464,511020,null,739281,785968,3828597,4421110,5034813,7706115,null,null,null,null,"
            "null,null,42600891,null,null,null,null,null,null,953727061,977339785,1050000781,null,null,null,null,null,1653701077,1851047007,2004509975,"
            "2060030878,null,2114534962,null,null,null,-1966526893,-1811856107,-1669074683,-1637722877,null,-1443948581,-1299734813,-1138515931,-879693526,"
            "null,null,null,-722698045,-552989373,null,-394811561,-381046425,null,-314070124,-180665322,null,null,null,null,-44832431,null,-9585224,-8144904,-"
            "4367513,null,null,null,null,null,null,null,null,-233530,null,-172430,-79765,-68231,null,null,null,-35156,null,-18248,-9322,null,-9050,-8400,-7043,"
            "-5647,null,-2426,-1706,null,-243,-96,null,null,null,null,null,null,null,null,null,null,null,-37,null,-8,-5,null,null,null,null,null,null,null,"
            "null,null,null,null,90,259,323,null,null,409,430,512,591,897,1691,1986,null,null,4219,null,null,null,null,7278,11922,30582,36898,70074,76883,"
            "91049,null,549287,null,null,null,null,null,null,null,null,null,5605243,null,8537125,null,null,null,null,null,null,1038542831,null,null,null,"
            "1724132112,null,null,null,null,null,null,null,-2017952596,null,-1899196677,-1790499019,-1727242905,null,-1660908302,null,-1604096987,-1389131910,"
            "null,-1231685062,null,-1028381131,-956707439,-859698840,null,null,null,-541776762,-409873900,null,null,-376606140,null,null,-243832839,-161331795,"
            "null,-44809482,-16019184,-8656147,-8392115,-5591755,null,null,null,null,null,null,-80625,null,-77173,-62041,null,null,null,null,null,null,null,"
            "null,-9017,-8257,null,-6337,null,-4989,null,null,null,null,null,-233,null,-95,null,-36,null,null,-5,null,87,146,null,264,311,null,null,null,null,"
            "437,484,568,null,719,null,null,912,null,null,2291,null,null,6893,7552,8593,14942,28779,null,33275,48704,59831,null,72969,82346,null,94096,535730,"
            "null,5534188,6496903,null,null,null,null,null,1791314956,null,null,null,null,-1800221912,-1775201599,null,null,-1661699756,null,null,-1556521261,-"
            "1426084861,null,null,null,-1046524553,null,null,null,null,null,null,-513179786,null,null,null,null,-279978305,-229289524,null,-71409588,null,-"
            "43236520,-16048753,-9831563,-9557527,null,null,-8377237,-7018729,null,null,null,-77343,null,null,-58515,null,-8558,null,-8002,-6498,-6166,null,-"
            "4267,null,-176,null,null,null,null,-6,null,85,88,118,219,null,null,null,null,null,null,null,null,null,null,709,791,null,1153,null,null,6544,7253,"
            "null,null,8095,9236,null,23206,null,null,null,34890,38827,57198,null,null,null,null,null,null,93448,null,null,null,null,null,null,null,null,null,"
            "null,null,null,null,null,null,-1582139482,null,null,null,-1127546934,null,null,null,-284897729,null,null,null,-90297287,-58464648,null,null,-"
            "19167861,null,null,null,null,null,null,null,-7746770,-6004995,null,null,null,null,-8798,null,null,null,null,null,null,null,-4812,-3280,null,-149,"
            "null,null,82,86,null,90,95,null,160,222,621,null,744,null,null,1428,null,6610,null,null,null,null,null,null,null,26412,null,null,null,null,57184,"
            "58203,91536,null,null,-1568391601,null,null,null,null,-90642357,-78511335,-58877453,-55169809,-25637634,-16587965,null,null,-6533209,null,null,"
            "null,null,null,null,null,null,null,70,84,null,null,null,null,null,null,null,null,null,236,null,672,null,null,null,1662,null,null,null,null,null,"
            "null,null,null,null,93300,null,null,-97530609,null,-87958388,null,null,null,null,null,-36858281,null,null,null,null,null,66,74,null,null,null,"
            "null,null,688,null,null,null,null,-135633246,null,null,null,null,null,61,null,null,78,null,null,null,null,null,65]";
        TreeNode *root = stringToTreeNode(line);

        TreeNode *ret = Solution().convertBiNode(root);

        string out = treeNodeToString(ret);
        cout << out << endl;
    }
    return 0;
}