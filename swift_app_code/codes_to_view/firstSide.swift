//
//  firstSide.swift
//  projectVr1
//
//  Created by Rie Ruash on 18/02/2021.
//

import SwiftUI

struct GridStack<Content: View>: View{
    let rows: Int
    let columns: Int
    let content: (Int, Int) -> Content
    
    var body: some View {
        VStack {
            ForEach(0..<rows, id: \.self) { row in
                HStack {
                    ForEach(0..<self.columns, id: \.self) { column in
                        self.content(row, column)
                    }
                }
            }
        }
    }
    
}

struct firstSide: View {
    @State private var squars1 = ["y","y","y","y","y","y","y","y","y"]
    var body: some View {
        //NavigationView {
            VStack {
                ZStack{
                    Image("background2")
                        .resizable()
                        .edgesIgnoringSafeArea(.all)
                    VStack{
                        
                        //Spacer()
                        Text("Please choose the \ncolors for the first side:")
                            .font(.title)
                            .foregroundColor(Color.white)

                            .bold()
                            .multilineTextAlignment(.center)
                        
                        //Spacer()
                        
                        Spacer()
                        //Spacer()
                        //Spacer()
                        
                        GridStack(rows: 3, columns: 3) { row, col in
                            //private
                            //private var button_color = squars1[row + col]
                            Button(action: {
                                //Same code using switch
                                switch self.squars1[row*3 + col] {
                                case "y":
                                    self.squars1[row*3 + col] = "b"
                                    //print(self.squars1)
                                case "b":
                                    self.squars1[row*3 + col] = "g"
                                    //print(self.squars1)
                                case "g":
                                    self.squars1[row*3 + col] = "o"
                                    //print(self.squars1)
                                case "o":
                                    self.squars1[row*3 + col] = "w"
                                    //print(self.squars1)
                                case "w":
                                    self.squars1[row*3 + col] = "r"
                                    //print(self.squars1)
                                default:
                                    self.squars1[row*3 + col] = "y"
                                    //print(self.squars1)
                                }
                                
                                //print(self.squars1[row*3 + col])
                            }){
                                Spacer()
                                /*Image("yellow_s")
                                 .resizable()
                                 .aspectRatio(1, contentMode: .fit)
                                 .aspectRatio(contentMode: .fit)
                                 .aspectRatio(contentMode: .fit)
                                 .aspectRatio(contentMode: .fit)
                                 .aspectRatio(contentMode: .fit)
                                 .border(Color.black, width: 2)*/
                                switch self.squars1[row*3 + col] {
                                case "y":
                                    Color.yellow
                                        .border(Color.black, width: 3)
                                        .padding(5.0)
                                case "b":
                                    Color.blue
                                        .border(Color.black, width: 3)
                                        .padding(5.0)
                                case "g":
                                    Color.green
                                        .border(Color.black, width: 3)
                                        .padding(5.0)
                                case "o":
                                    Color.orange
                                        .border(Color.black, width: 3)
                                        .padding(5.0)
                                case "w":
                                    Color.white
                                        .border(Color.black, width: 3)
                                        .padding(5.0)
                                default:
                                    Color.red
                                        .border(Color.black, width: 3)
                                        .padding(5.0)
                                }
                                //Color.yellow
                                
                                //.padding(8)
                                //Spacer()
                                //.fixedSize(horizontal: Bool, vertical: <#T##Bool#>)
                                //.border(Color.black, width: 3)
                                //.padding(5.0)
                                
                                //.frame(width: 3, height: 5, alignment: //Alignment)
                                
                                
                                /*.fontWeight(.bold)
                                 //.font(.title)
                                 .padding()
                                 .background(Color.white)
                                 .foregroundColor(.black)
                                 //.padding()
                                 .border(Color.white, width: 5)*/
                                Spacer()
                            }
                        }
                        Spacer()
                        //Spacer()
                        //Spacer()
                        //Spacer()
                        
                        //Spacer()
                        Spacer()
                        
                        NavigationLink(destination: secondSide()){
                                Text("Click to Continue")
                                    .fontWeight(.bold)
                                    .font(.title)
                                    .padding()
                                    .background(Color.white)
                                    .foregroundColor(.black)
                                    .padding(10)
                                    .border(Color.white, width: 2)
                            
                        }
                    }
                }
            }.navigationBarTitle(Text("First Side"))
    }
    
    
    //}

}
struct firstSide_Previews: PreviewProvider {
    static var previews: some View {
        firstSide()
    }
}
