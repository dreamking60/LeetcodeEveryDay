import java.util.HashSet;
import java.util.Random;
import java.util.Set;

class RandomizedSet_380_1 {
    private Set<Integer> randSet;

    public RandomizedSet_380_1() {
        randSet = new HashSet<>();
    }
    
    public boolean insert(int val) {
        if(randSet.contains(val)) {
            return false;
        }
        randSet.add(val);
        return true;
    }
    
    public boolean remove(int val) {
        if(!randSet.contains(val)) {
            return false;
        }
        randSet.remove(val);
        return true;
    }
    
    public int getRandom() {
        Random rand = new Random();
        int randNum = rand.nextInt(randSet.size());
        return (int) randSet.toArray()[randNum];
    }
}
// This method is too slow.