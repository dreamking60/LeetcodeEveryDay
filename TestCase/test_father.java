public class test_father {
    public static void main(String[] args) {
        Base base = new Sub();
        base.method(new Son());
    }
}

class Base {
    public void method(Father father) {
        System.out.println("Base method");
    }
}

class Sub extends Base {
    public void method(Son son) {
        System.out.println("Sub method");
    }
}

class Father {

}

class Son extends Father {

}