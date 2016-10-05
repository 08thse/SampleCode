// ExecutorService クラスを利用した ThreadPool のサンプル
// 参考書籍：即戦力にならないといけない人のための Java 入門

import java.util.concurrent.*;

public class ThreadPoolExample01 implements Runnable {

	// Output message template
	private static final String MSG_TEMPLATE = "output [%s] [No.%d]";
	private final String threadName;
	
	public ThreadPoolExample01(String threadName) {
		this.threadName = threadName;
	}
	
	public void run() {
		for(int i = 1; i < 20; i++){
			System.out.println(String.format(MSG_TEMPLATE, threadName, i));
		}
	}
	
	public static void main(String[] args) {
		ThreadPoolExample01 tp1 = new ThreadPoolExample01("thread1");
		ThreadPoolExample01 tp2 = new ThreadPoolExample01("thread2");
		ThreadPoolExample01 tp3 = new ThreadPoolExample01("thread3");
		
		ExecutorService executorService = Executors.newFixedThreadPool(3);
		executorService.execute(tp1);
		executorService.execute(tp2);
		executorService.execute(tp3);
		
		// スレッドの実行終了を待ってから終了処理に入る
		executorService.shutdown();
		
		try {
			if(!executorService.awaitTermination(1, TimeUnit.MINUTES)) {
				executorService.shutdownNow();
			}
		} catch (InterruptedException e) {
			e.printStackTrace();
			executorService.shutdownNow();
		}
	}
}
