

import junit.framework.TestCase;

//You can use this as a skeleton for your 3 different test approach
//It is an optional to use this file, you can generate your own test file(s) to test the target function!
// Again, it is up to you to use this file or not!





public class UrlValidatorTest extends TestCase {


   public UrlValidatorTest(String testName) {
      super(testName);
       UrlValidatorTest urlValidatorTest = new UrlValidatorTest("test1");
       urlValidatorTest.testManualTest();
   }

   
   
   public void testManualTest()
   {
//You can use this function to implement your manual testing
       long allowAllSchemes = UrlValidator.ALLOW_ALL_SCHEMES;
       UrlValidator urlValidator2 = new UrlValidator(null, null, allowAllSchemes);
       
       //Valid URLS
       System.out.println("Valid Manual Tests");
       if (urlValidator2.isValid("http://www.yahoo.com")) {
           System.out.println("url1 is valid - correct");
       } else {
           System.out.println("url1 is invalid - FAILED");
       }
       if (urlValidator2.isValid("https://www.amazon.com/")) {
           System.out.println("url2 is valid - correct");
       } else {
           System.out.println("url2 is invalid - FAILED");
       }
       if (urlValidator2.isValid("https://www.australia.gov.au/")) {
           System.out.println("url3 is valid - correct");
       } else {
           System.out.println("url3 is invalid - FAILED");
       }
       if (urlValidator2.isValid("http://google.com/")) {
           System.out.println("url4 is valid - correct");
       } else {
           System.out.println("url4 is invalid - FAILED");
       }
       if (urlValidator2.isValid("https://docs.google.com/document/d/1Ui-sTfm_f52wv2K5p8Ja1axxYya8A4Tz5hUwCnlI74c/edit")) {
           System.out.println("url5 is valid - correct");
       } else {
           System.out.println("url5 is invalid - FAILED");
       }
       if (urlValidator2.isValid("http://flip3.engr.oregonstate.edu:16943")) {
           System.out.println("url6 is valid - correct");
       } else {
           System.out.println("url6 is invalid - FAILED");
       }
       
       //Invalid URLS
       System.out.println("Invalid Manual Tests");
       if (urlValidator2.isValid("https://docs.google.com///1Ui-sTfm_f52wv2K5p8Ja1axxYya8A4Tz5hUwCnlI74c/edit")) {
           System.out.println("url7 is valid - FAILED");
       } else {
           System.out.println("url7 is invalid - correct");
       }
       if (urlValidator2.isValid("3ht://www.google.com")) {
           System.out.println("url8 is valid - FAILED");
       } else {
           System.out.println("url8 is invalid - correct");
       }
       if (urlValidator2.isValid("http://www.yahoo.com/#")) {
           System.out.println("url9 is valid - FAILED");
       } else {
           System.out.println("url9 is invalid - correct");
       }
       if (urlValidator2.isValid("http://aaa")) {
           System.out.println("url10 is valid - FAILED");
       } else {
           System.out.println("url10 is invalid - correct");
       }
       if (urlValidator2.isValid("http://www.go.com:-1")) {
           System.out.println("url11 is valid - FAILED");
       } else {
           System.out.println("url11 is invalid - correct");
       }
       if (urlValidator2.isValid("http:/google.com")) {
           System.out.println("url12 is valid - FAILED");
       } else {
           System.out.println("url12 is invalid - correct");
       }
       
       //Boundary URLs
       System.out.println("Boundary Manual Tests");
       if (urlValidator2.isValid("h3t://google.com")) {
           System.out.println("url13 is valid - correct");
       } else {
           System.out.println("url13 is invalid - FAILED");
       }
       if (urlValidator2.isValid("http://www.google.com:0")) {
           System.out.println("url14 is valid - correct");
       } else {
           System.out.println("url14 is invalid - FAILED");
       }
       if (urlValidator2.isValid("http://google.ca")) {
           System.out.println("url15 is valid - correct");
       } else {
           System.out.println("url15 is invalid - FAILED");
       }
       if (urlValidator2.isValid("google.com")) {
           System.out.println("url16 is valid - correct");
       } else {
           System.out.println("url16 is invalid - FAILED");
       }
       if (urlValidator2.isValid("http://")) {
           System.out.println("url17 is valid - correct");
       } else {
           System.out.println("url17 is invalid - FAILED");
       }
       if (urlValidator2.isValid("http:/google.com/file1/")) {
           System.out.println("url18 is valid - correct");
       } else {
           System.out.println("url18 is invalid - FAILED");
       }
	   
   }
   
   
   public void testYourFirstPartition()
   {
	 //You can use this function to implement your First Partition testing	   

   }
   
   public void testYourSecondPartition(){
		 //You can use this function to implement your Second Partition testing	   

   }
   //You need to create more test cases for your Partitions if you need to 
   
   public void testIsValid()
   {
	   //You can use this function for programming based testing

   }
   


}
