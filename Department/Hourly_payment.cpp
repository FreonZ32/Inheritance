#include"Hourly_payment.h"

const double Hourly_payment::get_payment()const
{
	return payment;
}
const unsigned int Hourly_payment::get_hours_worked()const
{
	return hours_worked;
}
const double Hourly_payment::get_final_pay()const
{
	return final_pay;
}
void Hourly_payment::set_payment(const double payment)
{
	this->payment = payment;
}
void Hourly_payment::set_hours_worked(const unsigned int hours_worked)
{
	if (hours_worked > 160)this->hours_worked = 160;
	else this->hours_worked = hours_worked;
}
void Hourly_payment::set_final_pay()
{
	this->final_pay = this->payment * this->hours_worked;
}

Hourly_payment::Hourly_payment()
{
	set_payment(0);
	set_hours_worked(0);
	set_final_pay();
}
Hourly_payment::Hourly_payment(const string& last_name, const string& first_name, const string& profession, const unsigned int experience,
	const double payment, const unsigned int hours_worked, const string& type_of_payment)
	:Profession(last_name, first_name, profession, experience, type_of_payment)
{
	set_payment(payment);
	set_hours_worked(hours_worked);
	set_final_pay();
#ifdef CONSTRUCT_DEBUG
	cout << "H_PConstrucror:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
Hourly_payment::~Hourly_payment()
{
#ifdef CONSTRUCT_DEBUG
	cout << "H_PDestructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}

ostream& Hourly_payment::print(ostream& os)const
{
	Profession::print(os);
	return os << "|", os.width(10), os << left << payment, os << "Руб/ч." << "|", os.width(8), os << left << hours_worked, os << "ч." << "|", os.width(8), os << left << final_pay, os << "Руб" << ";";
}
ofstream& Hourly_payment::print(ofstream& os)const
{
	Profession::print(os);
	os << "," << payment << "," << hours_worked << "," << final_pay;
	return os;
}

istream& Hourly_payment::input(istream& is)
{
	Profession::input(is);
	return is >> payment >> hours_worked;
}
ifstream& Hourly_payment::input(ifstream& is)
{
	Profession::input(is);
	string payment_buffer;
	getline(is, payment_buffer, ',');
	this->payment = stod(payment_buffer);
	string hours_worked_buffer;
	getline(is, hours_worked_buffer, ',');
	this->hours_worked = stoi(hours_worked_buffer);
	string final_pay;
	getline(is, final_pay);
	return is;
}