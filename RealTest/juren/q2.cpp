/**
 * struct Point {
 *	int x;
 *	int y;
 *	Point(int xx, int yy) : x(xx), y(yy) {}
 * };
 */
class Solution {
    public:
        /**
         * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
         *
         * 查询出现在怪物视野范围内的玩家有哪些。返回数组长度与monsters参数长度相同。对于每一个monster，从小到大返回其看到的玩家id列表。玩家id即玩家在players数组中的下标。
         * @param walls Point类vector<vector<>> 使用线段描述的墙壁。内层的vector<Point>长度恒定为2，表示A到B的线段。
         * @param players Point类vector 所有玩家的坐标。
         * @param monsters Point类vector<vector<>> 内层的vector<Point>长度恒定为2，第一个Point表示怪物的坐标，第二个Point表示怪物的朝向。由于Point使用整数坐标，所以朝向向量长度并不为1，需要自己normalize。朝向向量取值范围为[-1000,1000]并保证长度不为0
         * @return int整型vector<vector<>>
         */
        vector<vector<int> > query(vector<vector<Point> >& walls, vector<Point>& players, vector<vector<Point> >& monsters) {
            // write code here
        }
    };