float Term::evalTrig(float x) {
	// unity function
	if (function == "x") return x;

	// trig functions
	if (function == "sin") return sin(x);
	if (function == "cos") return cos(x);
	if (function == "tan") return tan(x);
	if (function == "asin") return asin(x);
	if (function == "acos") return acos(x);
	if (function == "atan") return atan(x);

	// hyper-trig functions
	if (function == "sinh") return sinh(x);
	if (function == "cosh") return cosh(x);
	if (function == "tanh") return tanh(x);
	if (function == "asinh") return asinh(x);
	if (function == "acosh") return acosh(x);
	if (function == "atanh") return atanh(x);

	if (function == "exp") return exp(x);

	return 1;
}

float Term::eval(float x) {
	//printf("c: %d, exp: %d, f:%s, val: %f\n", coef, exp, function.c_str(), coef * pow(evalTrig(x), exp));
	if (exponent == 0) return coef;
	return coef * pow(evalTrig(x), exponent);
}

void Term::print() {
	printf("coef: %f, power: %f, function: %s\n", coef, exponent, function.c_str());
}

// =================================[Exp functions]===========================

Exp::~Exp() {
	terms.clear();
}

float Exp::eval(float x) {
	float y = 0;
	for (Term term : terms) y += term.eval(x);
	return y;
}

float Exp::string2number(string str) {
	/*
	int num = 0;
	int place = 1;
	reverse(str.begin(), str.end());
	for (char d : str) {
		num += (d - '0') * place;
		place *= 10;
	}
	return num;
	*/
	stringstream ss(str);
	float res;
	ss >> res;
	return res;
}

void Exp::print() {
	for (Term term : terms) term.print();
}

// accExpted syntax: [+/-]_[digit(s)]_[function: just x or trig function]_^_[digit(s)], _ == any number of spaces (0 or more)
// syntax is split into 5 stages: from 0 to 4 searching for the above respectivly
void Exp::parse(string expression) {
	string errorMsg = "Expression syntax error";
	Term *term = new Term();
	terms.clear();

	int stage = 0;
	for (int i = 0; i < expression.size(); ++i) {
		char c = expression[i];
		if (c == ' ') continue;

		string num = "";
		switch (stage) {
		case 0:
			if (c != '+' && c != '-') {
				--i;
			}
			else {
				if (c == '-') term->coef *= -1;
			}
			++stage;
			break;

		case 1:
			num = "";
			if (!isdigit(c) && c != '-') {
				--i;
			}
			else {
				while (isdigit(expression[i]) || expression[i] == '.' || expression[i] == '-') {
					num += expression[i];
					++i;
				}
				--i;
				term->coef *= string2number(num);
			}
			++stage;
			break;

		case 2:
			if (!isalpha(c)) {
				if (c == '^') throw errorMsg;
				terms.push_back(*term);
				term = new Term();
				stage = 0;
			}
			else {
				if (c == 'x') {
					term->function = "x";
				}
				else {
					while (isalpha(expression[i])) {
						term->function += expression[i];
						++i;
					};
					while (expression[i] == ' ') ++i;
					if (expression[i] != '(') throw errorMsg;
					while (expression[i] != ')') ++i;
				}
				++stage;
			}
			break;

		case 3:
			if (c != '^') {
				--i;
				terms.push_back(*term);
				term = new Term();
				stage = 0;
			}
			else {
				++stage;
			}
			break;

		case 4:
			if (!isdigit(c) && c != '-') throw errorMsg;
			num = "";
			while (isdigit(expression[i]) || expression[i] == '.' || expression[i] == '-') {
				num += expression[i];
				++i;
			}
			--i;
			term->exponent = string2number(num);

			terms.push_back(*term);
			term = new Term();
			stage = 0;
			break;
		}
	}

	if (stage == 2) {
		term->function = "x";
		term->exponent = 0;
		terms.push_back(*term);
	}
	else if (stage == 3) {
		term->exponent = 1;
		terms.push_back(*term);
	}
	else {
		delete term;
	}
}
