

bool isPalindrome(int x){
	long check=0, temp = x;
	while (temp > 0){
		check += temp%10;
		check *= 10;
		temp /= 10;
	}
	if (check/10 == x) return true;
	return false;
}
