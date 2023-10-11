/*
    HR ของบริษัทเน็ตเวิร์คทำการกรอกข้อมูลพนักงานลงไปในระบบคำนวณฐานภาษีเพื่อเตรียมส่งยอดภาษีสู่ฝ่ายบัญชี โดยจะหักภาษี ณ ที่จ่าย 7% ของเงินเดือนที่ได้ ให้คุณคำนวณภาษีพนักงานทั้งหมดที่บริษัทของคุณต้องชำระภายในปีนี้ (กรอกเลข -1 ถือเป็นการสิ้นสุดการกรอก และทำการสรุปผลภาษีที่ต้องชำระภายในปีนี้) และสร้างฟังก์ชันที่ระบุคนที่ต้องชำระภาษีเยอะที่สุดในบริษัทมาแสดงในผลสรุปยอดของบริษัทด้วย

    Test case:
        Employee 1's Name : 
            Omar
        Sarary (Bath/Month) : 
            12750
        Employee 2's Name : 
            Alice
        Sarary (Bath/Month) : 
            15900
        Employee 3's Name : 
            Max
        Sarary (Bath/Month) : 
            19860
        Employee 4's Name : 
            -1
    Output:
        All salary per month: 48,510.00 Bath
        All salary per year: 582,120.00 Bath
        Tax (7% per year) : 40,748.40 Bath
        Most tax in company : Max (16,682.40 Bath per year)

    Test case:
        Employee 1's Name : 
            John
        Sarary (Bath/Month) : 
            15780
        Employee 2's Name : 
            Oven
        Sarary (Bath/Month) : 
            16890
        Employee 3's Name : 
            May
        Sarary (Bath/Month) : 
            17870
        Employee 4's Name : 
            Bill
        Sarary (Bath/Month) : 
            22100
        Employee 5's Name : 
            -1
    Output:
        All salary per month: 72,640.00 Bath
        All salary per year: 871,680.00 Bath
        Tax (7% per year) : 61,017.60 Bath
        Most tax in company : Bill (18,564.00 Bath per year)
*/
#include <stdio.h>
#include <string.h>

struct Employee {
    char Name[20];
    float Salary;
};

int main() {
    struct Employee employees[100];
    int numEmployees = 0;
    float totalSalary = 0;
    float totalTax = 0;
    float maxTax = 0;
    char maxTaxEmployee[20];

    do {
        printf("Employee %d's Name : ", numEmployees + 1);
        scanf("%s", employees[numEmployees].Name);

        if (strcmp(employees[numEmployees].Name, "-1") == 0) {
            break;
        }

        printf("Salary (Bath/Month) : ");
        scanf("%f", &employees[numEmployees].Salary);
        totalSalary += employees[numEmployees].Salary;

        numEmployees++;
    } while (numEmployees < 100);

    // คำนวณภาษี
    totalTax = totalSalary * 0.07;

    // หาคนที่ต้องชำระภาษีเยอะที่สุด
    for (int i = 0; i < numEmployees; i++) {
        float tax = employees[i].Salary * 12 * 0.07;
        if (tax > maxTax || i == 0) {
            maxTax = tax;
            strcpy(maxTaxEmployee, employees[i].Name);
        }
    }

    // แสดงผลลัพธ์
    printf("All salary per month: %.2f Bath\n", totalSalary);
    printf("All salary per year: %.2f Bath\n", totalSalary * 12);
    printf("Tax (7%% per year) : %.2f Bath\n", totalTax);
    printf("Most tax in company : %s (%.2f Bath per year)\n", maxTaxEmployee, maxTax);

    return 0;
}
