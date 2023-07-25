import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss']
})
export class AppComponent {
  title = 'Bio informatica 2023';

  mainString: string = "AAAAATCGG";
  subString: string = "ATAGG";


  ngOnInit(){
    console.log((<any>window).Module);
  }

  
}

