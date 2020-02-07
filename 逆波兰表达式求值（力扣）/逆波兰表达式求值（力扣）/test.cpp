#define _CRT_SECURE_NO_WARNINGS 1
class Solution {
public: int evalRPN(<string>& tokens) {
			Stack<Integer> stack = new Stack<>();
			int result;
			for (int i = 0; i < tokens.length; i++) {
				int temp;
				switch (tokens[i]) {
				case "+":
					result = stack.pop() + stack.pop();
					stack.push(result);
					break;
				case "-":
					temp = stack.pop();
					result = stack.pop() - temp;
					stack.push(result);
					break;
				case "*":
					result = stack.pop() * stack.pop();
					stack.push(result);
					break;
				case "/":
					temp = stack.pop();
					result = stack.pop() / temp;
					stack.push(result);
					break;
				default:
					stack.push(Integer.parseInt(tokens[i]));
					break;
				}
			}

			return stack.peek();
}


};