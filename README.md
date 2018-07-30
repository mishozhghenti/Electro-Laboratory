# Electro-Laboratory
# Mushroom greenhouse controller. Project Name: Smalle 


**Mikheil Zhghenti**:**mzhgh14@freeuni.edu.ge**<br> **Otar Jankhoteli**:**ojank14@freeuni.edu.ge**

-----------------------------------------------------------
Smalle: it's a mushrooms greenhouse controller device which helps workers to detect high level of CO2 in the air and also guesses if mushroom is ready to be picked.

Distance measurement sensor is located horizontally and when small region of mushrooms will be grown sensor detects this and says that it's time to be picked this region of mushrooms.
This device makes it easy and comfortable to control greenhouse.

-----------------------------------------------------------
# შესავალი
MACS-ის ბოლო კურსე გადავწყვიტე, რომ საუნივერსიტეტო განათლებიდან არა მხოლოდ software development-ის მიმართულებით განვითარებულიყავი, არამედ hardware-ის მხარესაც გამეგო საფუძვლები და ის პრინციპები, რომლებიც software-ს არსებობის შესაძლებლობას აძლევდა.

რაღაც დონეზე მქონდა აქამდე შეხება მიროკონტროლერებზე, კონკრეტულად **Raspberry Pi**-ზე, მაგრამ მოწყობილობების "შინაგან ორგანოებს" ვერ ვცნობდი და შესაბამისად არ მესმოდა კარგად როლები მოწყობილობაში როგორ ნაწილდებოდა.

კურსის დასაწყისშივე რამდენიმე "შინაგანი ორგანო" "გავიცანით", ზოგის ფუნქციონალს ვიზუალით მივხვდით, ზოგის - მინიშნებებით. შემდეგ კოდშიც ჩავიხედეთ და აქაური **Hello World!**-იც დავწერეთ.

სამსახურიც მომეხმარა hardware-ებში კარგად გარკვევაში. მუშაობა მომიწია **watchdog**-ებზე. მიზანი იყო რომ ამ მოწყობილობას დაეჭირა კონკრეტული მოქმედებების **event**-ი. ანუ ერთგვარი დარაჯი კონკრეტული მიმართულებით. მაგალითად დაეფიქსირებინა კარის გაღება, დაკეტვა, დენის გათიშვა და ასე შემდეგ.

Hardware-ებზე მუშაობისას ყველაზე მნიშვნელოვან საკვანძო განსხვავებას რასაც შევხვდი, software-ებზე მუშაობებისგან განსხვავებით იყო ის, რომ როდესაც software-ებზე პროექტს ვაწყობთ უფრო "თამამად" და შედარებით "ხარბად"გვიწევს მუშაობა. Hardware-ბზე ყველაზე ერთ-ერთ პრინციპს რასაც შევეჯახე იყოს request/response მოწყობილობის პროცესორთან. მაშინ როცა შეჩვეული ვიყავი ძლიერ პროცესორებს და მარტივ მოქმედებების შედეგ წამის მეასედებზე ვხედავდი, აქ მოწყობილობებზე მუშაობისას კი ხშირად გვიწევს **sleep()**-ის გამოყენება, სუსტი core-ების გამო(დაბალი GHz).

![img_20180426_153814](https://user-images.githubusercontent.com/11095204/39304734-b96cb490-496b-11e8-8fbf-1888fd913792.jpg)
![img_20180426_153828](https://user-images.githubusercontent.com/11095204/39304735-b9c7586e-496b-11e8-9f28-585a4e76d4e8.jpg)

# ინსპირაცია
კურსის განმავლობაში დაგროვებული შესაძლებლობებით და იდეებით გადავწყვიტე პროექტად ისეთი რამ შემერჩია, რომელიც არა მხოლოდ ცოდნას გამიღრმავებდა კონკრეტული მიმართულებით არამედ რეალურ, ღირებულ გამოცდილებას შემძენდა.

მეგობრის მამას აქვს **სოკოს სათბური**. მისი მოვლა ყოველთვის შრომატევადია. სეზონურად ხდება მისი შემოწმება და პროფილაქტიკა.

როგორც ცნობილია სოკო ძალიან მალე იზრდება და ზრის პროცესში დიდი რაოდენობით **CO2**-ს გამოყოფს. დაგროვებული აირის *"გასანეიტრალებლად"* ხდება პერიოდული განიავება ან სოკოებთან ერთად სხვა ისეთი მცენარეების მოყვანა, რომლებიც დიდი რაოდენობით **CO2**-ს ეფექტურად ამუშავებენ.

ჩვენს შემთხვევაში სათბურის პერიოდულად ნიავდება, რაც გარკვეულ წილად საფრთის შემცველია, რადგან გარედან შემოსულ ჰაერში შესაძლოა მავნე ნივთიერებები შემოჰყეს, ან ვირუსები და სოკო გააფუჭოს. ამიტომ ეს პროცედურა დიდ ყურადღებას მოითხოვს.

პირველი რისი შეცვლად მომინდა ეს იყო შემექმნა ზემოთ აღნიშნული მექანიზმის, გარკვეულწილად, ალტერნატივა და მისი გაუმჯობესება. გაუმჯობესება იმ გაგებით, რომ ახალი შექმნილი მოვლის მოდელი კიდევ უფრო **ინოვაციური**, **კრეატიული** და **უფრო კომფორტული** ყოფილიყო სათბურის თანამშრომლებისთვის.

# Idea

ჩვენი შერჩეული იდეა სათბურში დაგროვებულ **CO2**-ის დონეს განსაზღვრავს და თუ მისი ნიშნული განსაზღვრულ მაქსიმუმზეა, მაშინ ეს არის იმის ნიშანი რომ სათბური საჭიროებს განიავებას, სუფთა ჰაერის შემოშვებას.

ასევე ჩვენი მოწყობილობა გვაძლევს შესაძლებლობას არა მხოლოდ ნახშირორჟანის დონის კონტოლის საშუალებას, არამედ იმის განსაზღვრაშიც გვეხმარება თუ როდისაა **სოკოს მოკრეფვის ზუსტი დრო**. (ჰორიზონტალურად დამაგრებული მანძილის სენსორის მიხედვით, ვადგენთ სათბურის კონკრეტულ რეგიონზე მისი "მომწიფების" დროს. თუ უკვე მზადაა მოსაკრეფად მოწყობილობა გვატყობინებს.)




# Process

![img_20180728_195245](https://user-images.githubusercontent.com/11095204/43365494-d1c08360-933e-11e8-8cab-1460e3997349.jpg)
![img_20180728_195248](https://user-images.githubusercontent.com/11095204/43365495-d1e5474a-933e-11e8-99bb-2d0365710921.jpg)
![img_20180728_201551](https://user-images.githubusercontent.com/11095204/43365496-d209b76a-933e-11e8-815c-d08b3a9062d6.jpg)
![img_20180728_201557](https://user-images.githubusercontent.com/11095204/43365497-d22c4ece-933e-11e8-8c5a-b7f067c0c537.jpg)
![img_20180728_201919](https://user-images.githubusercontent.com/11095204/43365532-2f16824e-933f-11e8-9474-2a0544a77201.jpg)
![img_20180728_202722](https://user-images.githubusercontent.com/11095204/43365499-d2708bd4-933e-11e8-8229-14d4631974c3.jpg)


# Video Demonstrations:
https://www.youtube.com/watch?v=_N2cG0d-Fzo

