import { Component } from '@angular/core';

@Component({
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.scss'],
})
export class AppComponent {
  title = 'Bio informatica 2023';

  mainString: string = '';
  subString: string = '';
  messages: string[] = [];

  ngOnInit() {}

  calcSpacedSeeds() {
    this.messages.splice(0, this.messages.length);
    let result: any = (<any>window).Module.SpacedSeeds(
      this.mainString,
      this.subString
    );
    let resultArray = this.toStringArray(result);
    for (let index = 0; index < resultArray.length; index++) {
      this.messages.push(resultArray[index]);
    }
  }

  toStringArray(stringVector: any) {
    let result: string[] = [];
    for (var i = 0; i < stringVector.size(); i++) {
      result[i] = stringVector.get(i);
    }

    return result;
  }

  
  get hasValues() : boolean {
    return this.mainString != undefined &&
            this.mainString.length > 0 &&
            this.subString != undefined &&
            this.subString.length > 0;
  }
  
}
