# Midterm
期中 Project

Deadline: 2016/11/6 23:59

任選 (A) 或 (B) 作答

(A) (60 分)

Client 端傳遞兩個數字給 Server, Server 回傳相加後之結果給 Client

(B) (100 分)

猜數字

Client 與 Server 建立連線後, Server 亂數產生一由左至右排列好的四個數碼（數碼0可以在最前面，且數碼不可以重複出現被使用）， 例如1847，讓 client 去猜。 

Client 輸入一組 4 位數字後傳遞給 Server, Server 會給 client 提示，譬如玩者猜了6149，則提示是1A1B，其中A表示有這個數字，且數字是在正確的位置， B表示有這個數字，但位置不對；因為數字4被猜對了位置也正確，而數字1被雖猜對了但位置不正確，所以得到1A1B。
