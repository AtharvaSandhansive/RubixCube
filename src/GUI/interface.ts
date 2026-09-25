//interface.ts

import arrowpath from "../assets/arrow.png";

export class Interface{

    private body: HTMLElement;
    private face: HTMLElement;
    private arrow:HTMLElement;

    constructor() {
        this.body = document.body;

        this.face = document.createElement("div");
        this.face.classList.add("cube-container");
        this.body.appendChild(this.face);

        this.arrow = document.createElement("div");
        this.arrow.classList.add("button-container");
        this.face.appendChild(this.arrow);

        this.createFace();
        this.createButtons();
    }

    private createFaceElement(className: string): HTMLElement {

        const face = document.createElement("div");

        face.classList.add("cube-face", className);

        for (let i = 0; i < 9; i++) {

            const sticker = document.createElement("div");

            sticker.classList.add("sticker");

            face.appendChild(sticker);
        }

        return face;
    }

    private createButton(className: string): HTMLElement {

        const button = document.createElement("button");

        button.classList.add("cube-arrow", className);

        const image = document.createElement("img");

        image.src = arrowpath;

        button.appendChild(image);

        button.addEventListener("click", () => {
            console.log(className);
        });

        return button;
    }

    private createFace(): void {

        const mainFace = this.createFaceElement("main-face");
        const upFace = this.createFaceElement("up-face");
        const downFace = this.createFaceElement("down-face");
        const leftFace = this.createFaceElement("left-face");
        const rightFace = this.createFaceElement("right-face");
        const backFace = this.createFaceElement("back-face");

        this.face.appendChild(mainFace);
        this.face.appendChild(upFace);
        this.face.appendChild(downFace);
        this.face.appendChild(leftFace);
        this.face.appendChild(rightFace);
        this.face.appendChild(backFace);
    }

    private createButtons(){
        const firstRowRight = this.createButton("first-row-right");
        const firstRowLeft = this.createButton("first-row-left");
        const secondRowRight = this.createButton("second-row-right");
        const secondRowLeft = this.createButton("second-row-left");
        const thirdRowRight = this.createButton("third-row-right");
        const thirdRowLeft = this.createButton("third-row-left");

        const firstColumnUp = this.createButton("first-column-up");
        const firstColumnDown = this.createButton("first-column-down");
        const secondColumnUp = this.createButton("second-column-up");
        const secondColumnDown = this.createButton("second-column-down");
        const thirdColumnUp = this.createButton("third-column-up");
        const thirdColumnDown = this.createButton("third-column-down");

        this.arrow.appendChild(firstRowRight);
        this.arrow.appendChild(firstRowLeft);

        this.arrow.appendChild(secondRowRight);
        this.arrow.appendChild(secondRowLeft);

        this.arrow.appendChild(thirdRowRight);
        this.arrow.appendChild(thirdRowLeft);

        this.arrow.appendChild(firstColumnUp);
        this.arrow.appendChild(firstColumnDown);

        this.arrow.appendChild(secondColumnUp);
        this.arrow.appendChild(secondColumnDown);

        this.arrow.appendChild(thirdColumnUp);
        this.arrow.appendChild(thirdColumnDown);
    }

    public updateGraphics(): void {

    }
}
