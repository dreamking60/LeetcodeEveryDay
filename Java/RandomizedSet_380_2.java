import java.util.Map;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class RandomizedSet_380_2 {
    private Map<Integer, Integer> map;
    private List<Integer> list;

    public RandomizedSet_380_2() {
        map = new HashMap<>();
        list = new ArrayList<>();
    }

    public boolean insert(int val) {
        if(map.containsKey(val)) {
            return false;
        }
        list.add(val);
        map.put(val, list.size()-1);
        return true;
    }

    public boolean remove(int val) {
        if(!map.containsKey(val)) {
            return false;
        }
        int index = map.get(val);
        int lastElement = list.get(list.size()-1);
        list.set(index, lastElement);
        map.put(lastElement, index);
        list.remove(list.size()-1);
        map.remove(val);
        return true;
    }

    public int getRandom() {
        int randNum = (int) (Math.random() * list.size());
        return list.get(randNum);
    }
}
