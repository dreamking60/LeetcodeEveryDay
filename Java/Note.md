## java switch case语句
```java
switch(expression){
    case value :
       //语句
       break; //可选
    case value :
       //语句
       break; //可选
    //你可以有任意数量的case语句
    default : //可选
       //语句
}
```

## Integer to String
Three ways.
```java
Integer.toString()

String.valueOf()

String.format()
```

## string length
```
String.length()
```

## getOrDefault
```java
import java.util.HashMap;

class Main {
    public static void main(String[] args) {
        // 创建一个 HashMap
        HashMap<Integer, String> sites = new HashMap<>();

        // 往 HashMap 添加一些元素
        sites.put(1, "Google");
        sites.put(2, "Runoob");
        sites.put(3, "Taobao");
        System.out.println("sites HashMap: " + sites);

        // key 的映射存在于 HashMap 中
        // Not Found - 如果 HashMap 中没有该 key，则返回默认值
        String value1 = sites.getOrDefault(1, "Not Found");
        System.out.println("Value for key 1:  " + value1);

        // key 的映射不存在于 HashMap 中
        // Not Found - 如果 HashMap 中没有该 key，则返回默认值
        String value2 = sites.getOrDefault(4, "Not Found");
        System.out.println("Value for key 4: " + value2);
    }
}
```

## ToUpper Case
```
char toUpperCase(char ch)
```

## Node
```java
public class ListNode {
   int val;
   ListNode next;

   public ListNode() {}

   public ListNode(int val) {
      this.val = val;
   }

   public ListNode(int val, ListNode next) {
      this.val = val;
      this.next = next;
   }
}
```