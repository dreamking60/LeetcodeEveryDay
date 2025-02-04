import org.apache.commons.exec.CommandLine;
import org.apache.commons.exec.DefaultExecutor;
import org.apache.commons.exec.Executor;

public class HttpieExecExample {
    public static void main(String[] args) throws Exception {
        // 构建命令行调用
        CommandLine cmdLine = new CommandLine("https");
        cmdLine.addArgument("google.com");

        // 执行命令
        Executor executor = new DefaultExecutor();
        int exitValue = executor.execute(cmdLine);
        System.out.println("Exit value: " + exitValue);
    }
}