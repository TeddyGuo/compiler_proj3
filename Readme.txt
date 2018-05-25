make 之後會產生執行檔 gen 代表 generator
(不要吐槽，我只是懶得每次打generator 才打gen)

使用方法為./gen filename.rust

因為C main function 寫在parser.y 文件裡，所以好像只能這樣用嗎？我也不確定

總之請這樣使用吧！！！

parser.y 裡將除了integer-type 之外的變數文法都刪掉了
就如proj3.pdf 裡所給予的限制去做修改

* No READ statements.
* No declaration of use of arrays.
* No floating-point numbers.
* No string variables.

不過像常數宣告如：

  let a = 10;
  let b = true;
  let s = "string";

依然合法，除了float-type constant declaration

scanner.l 多了一個char array 存rust檔案裡的內容，然後最後這些會被當作註解寫在
jasm檔案裡

我原本也想照範例的方式寫進檔案，但因為我產生jasm檔案內容的方式跟範例的想必不同
我無法將它們放到對應的位置，因此註解都放置在最下面

每次編譯完一個程式都會產生一個jasm，一個local.out，一個dump.out

jasm 當然就是專案要產生的內容

local.out 是編譯完rust檔案之後，裡面會紀錄local variables的數目與相應的counter

dump.out 之前就有，裡面存所有的ID，相對的類型與出現的行數，雖然行數現在會因為
我插入方法的改變而錯誤，不過還是可以確認有什麼ID

專案目前如果遇到if-else statement，if 或 else 裡如果超過一行就會錯誤

存粹 if statement 倒是沒問題，我自己有多放一個ifstmt.rust 測試這件事

while statement 也是執行正確

以上感謝您的閱讀，祝您暑假愉快，讓我All pass

 > < b 謝謝
