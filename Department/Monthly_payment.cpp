#include"Monthly_payment.h"

Monthly_payment::Monthly_payment(const string& last_name, const string& first_name, const string& profession, const unsigned int experience,
	const double payment, const unsigned int hours_worked, const string& type_of_payment)
	:Hourly_payment(last_name, first_name, profession, experience, payment ,1, "by_month")
{
#ifdef CONSTRUCT_DEBUG
	cout << "H_PConstrucror:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}
Monthly_payment::~Monthly_payment()
{
#ifdef CONSTRUCT_DEBUG
	cout << "M_PDestructor:\t" << this << endl;
#endif // CONSTRUCT_DEBUG
}

ostream& Monthly_payment::print(ostream& os)const
{
	Profession::print(os);
	return os << "|", os.width(10), os << left << get_payment(), os << "Руб/м." << "|", os.width(8), os << left << get_final_pay(), os << "Руб" << ";";
}
ofstream& Monthly_payment::print(ofstream& os)const
{
	Profession::print(os);
	os << "," << get_payment() << "," << get_final_pay();
	return os;
}

istream& Monthly_payment::input(istream& is)
{
	Profession::input(is);
	double d; is >> d;
	set_payment(d);
	set_hours_worked(160);
	return is;
	
}
ifstream& Monthly_payment::input(ifstream& is)
{
	Profession::input(is);
	string payment_buffer;
	getline(is, payment_buffer, ',');
	set_payment(stod(payment_buffer));
	string final_pay;
	set_hours_worked(160);
	getline(is, final_pay);
	return is;
}